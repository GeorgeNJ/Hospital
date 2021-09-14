#include <iostream>
#include <fstream>

using namespace std;

int verbose = 0;
int health = 0;

/* write to file class */
class Person {
	public:
		/*
		void Person_details(){
			cout << det.name << "\t" << det.data <<  endl;
		}
		void Person_details() {
			cout << det.name << "\t" << det.data << "\t "<<ntfy << endl; 

		} */

};


class Temperature {
		public:
			double temp;
			string notify;
			double temp_fn() {
				cout << "Temp: ";
				cin >> temp;
				if (temp > 38) {
					health = 1;
					notify = "Critical Temp Detected";		 

				}
                                else {
                                	notify = "normal";
                                }
				return temp;
			}			
};


class Hb {
	 public:
                        double heart_beat;
                        string notify;
                        double hb_fn() {
                                cout << "Pulse: ";
                                cin >> heart_beat;
                                if (heart_beat > 120) {
					health = 1;
                                        notify = "Critical Pulse Detected";

                                }
                                else {
                                	notify = "normal";
                                }
                                return heart_beat;
                        }



};


class Oxy {
  	public:
                        double oxy;
                        string notify;
                        double oxy_fn() {
                                cout << "Oxygen level: ";
                                cin >> oxy;
                                if (oxy < 90) {
					health = 1;
                                        notify = "Critical Oxygen Level";

                                }
                                else {
                                	notify = "normal";
                                }
                                return oxy;
                        }




};

class Bp {
	  public:
                        double bp;
                        string notify;
                        double bp_fn() {
                                cout << "Blood Pressure: ";
                                cin >> bp;
                                if (bp > 160) {
					health = 1;
                                        notify = "Critical Blood Pressure Detected";

                                }
                                else {
                                	notify = "normal";
                                }
                                return bp;
                        }




};

/* Get data from each person */
class Acquisition{
        public:
        	double val_temp;
        	double val_hb;
        	double val_oxy;
        	double val_bp;
		string name;
                void get_method() {
		     cout<< "Name: " ;
		     cin >> name;
		     Temperature t;

                     double val_temp = t.temp_fn();
		     Hb h;
		     double val_hb = h.hb_fn();
		     Oxy o;
                     double val_oxy = o.oxy_fn();
                     Bp b;
                     double val_bp = b.bp_fn();
		     cout << "##########################################################" << endl;
		     cout << endl;
		     cout <<"\t" <<"PATIENT MONITORING SYSTEM" << endl;
		     cout << endl;
		     cout << "Name	: " << name << endl;
		     cout << "Temp	: " << val_temp << "\t" << t.notify << endl;
                     cout << "Pulse	: " << val_hb << "\t" << h.notify << endl;
		     cout << "Oxygen	: " << val_oxy << "\t" << o.notify << endl;
                     cout << "Bp 	: " << val_bp << "\t" << b.notify << endl;
		     cout << endl;
	   	     cout << "#########################################################" << endl;

		     fstream my_file;
  		     my_file.open(name+".txt", ios::out);
  		     if (!my_file){
  		     	cout << "File not created!\n";
  		     }
		     else{
		     	if (verbose == 1){
    		     		cout << "File created successfully!\n";
		     	}
		     	if (health == 1){
		     		my_file << "The person is unhelthy \n";
		     	}
		     	else{
		     		my_file << "The person is helthy \n";
		     	}
    		     	my_file << "Temp: " << val_temp << "(" << t.notify << ")" "\t";
    		     	my_file << "Pulse: " << val_hb << "(" << h.notify << ")" "\t";
    		     	my_file << "Oxygen: " << val_oxy << "(" << o.notify << ")" "\t";
    		     	my_file << "Blood pressure: " << val_bp << "(" << b.notify << ")" "\t";
		     	my_file.close(); 
  		     }
                } 
};


int main (int argc, char *argv[]) {
	Acquisition a;
	a.get_method();
	return 0;
}
