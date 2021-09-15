#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "sensor.h"

using namespace std;

int verbose = 0;

class Person
{
private:
	string name;
public:
	void putPersonDetails(string n)
	{
		name = n;
	}

	string getPersonName()
	{
		return name;
	}

};

class Patient : public Person
{
private:
	string id;

	TemperatureSensor ts;
	HeartBeatSensor hbs;
	So2Sensor os;
	BloodPressureSensor bps;

public:
	Patient() : ts(35.5,38.5), hbs(60,100), os(80,100), bps(100,160){}

	void putPatientId(string i)
	{
		id = i;
	}

	string getPatientId()
	{
		return id;
	}

	void putPatientStates()
	{
		float t;
		int hb,o,bp;

		cout << "Temperature: ";
        cin >> t;
        ts.setValue(t);
        cout << "Pulse: ";
        cin >> hb;
        hbs.setValue(hb);
        cout << "Oxygen level: ";
        cin >> o;
        os.setValue(o);
        cout << "Blood Pressure: ";
        cin >> bp;
        bps.setValue(bp);
	}
	
	void savePatientDetails()
	{
		time_t now = time(0);
		char* dt = ctime(&now);
	
		fstream my_file;
	  	my_file.open(id+".txt", std::ios::app);
	  	if (!my_file)
	  	{
	  		cout << "File not created!\n";
	  	}
		else
		{
			if (verbose == 1)
			{
	    	cout << "File created successfully!\n";
			}
			my_file << "Date: " << dt << "\n";
			my_file << "Name: " << getPersonName() << "\n";
	    	my_file << "Temp: " << ts.readValue() << "(" << ts.getState() << ")" "\t";
	    	my_file << "Pulse: " << hbs.readValue() << "(" << hbs.getState() << ")" "\t";
	    	my_file << "Oxygen: " << os.readValue() << "(" << os.getState() << ")" "\t";
	    	my_file << "Blood pressure: " << bps.readValue() << "(" << bps.getState() << ")" "\n\n";
			my_file.close(); 
	  	}
	}
	
	void printPatientDetails()
	{
		cout << "##########################################################" << endl;
		cout << endl;
		cout <<"\t" <<"PATIENT MONITORING SYSTEM" << endl;
		cout << endl;
		cout << "Name: " << getPersonName() << "\n";
		cout << "Temp	: " << ts.readValue() << "\t" << ts.getState() << endl;
	    cout << "Pulse	: " << hbs.readValue() << "\t" << hbs.getState() << endl;
		cout << "Oxygen	: " << os.readValue() << "\t" << os.getState() << endl;
	    cout << "Bp 	: " << bps.readValue() << "\t" << bps.getState() << endl;
		cout << endl;
		cout << "#########################################################" << endl;
		cout << endl;
	}

	void printPatientRecord()
	{
		string line;
		fstream my_file1;
		my_file1.open(id+".txt", std::ios::in);
		if (!my_file1)
	  	{
	  		cout << "File not found!\n";
	  	}
	  	else
	  	{
	  		while ( getline (my_file1,line) )
    		{
      			cout << line << '\n';
    		}
    		my_file1.close();
	  	}
	}

	char * getPatientRecord()
	{
		streampos size;
  		char * memblock;

		ifstream my_file2 (id+".txt", ios::in|ios::binary|ios::ate);
		if (my_file2.is_open())
		{
			size = my_file2.tellg();
			memblock = new char [size];
			my_file2.seekg (0, ios::beg);
			my_file2.read (memblock, size);
			my_file2.close();
			return memblock;
		}
		else
		{
			cout << "Unable to open file";
			return NULL;
		}
	}
};

