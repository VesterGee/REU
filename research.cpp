
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class Process{
	int beginning, end, length, requestsGenerator, interleavingGenerator;
	vector<int> process;
public:
	Process(int beginning, int end, int length, int requestsGenerator, int interleavingGenerator){
		this->beginning = beginning;
		this->end = end;
		this->length = length;
		this->requestsGenerator = requestsGenerator;
		this->interleavingGenerator = interleavingGenerator;;

	}
	
	void addRequest(int newNum){
		process.push_back(newNum);
	}

	int randomGenerator(){
		int random = rand() % (end-beginning) + beginning;
		for(int i = 0; i<length; i++)
		{
			addRequest(random);
		}
		return random;
	}
	
	int getBeginning(){
		return beginning;
	}

	int getEnd(){
		return end;
	}

	int getLength(){
		return length;
	}

	int getRequestsGen(){
		return requestsGenerator;
	}

	int getInterleavingGen(){
		return interleavingGenerator;
	}

	void printProcess(){
		//cout<< "Printing Process of"<< length <<"random integers between" << beginning << "and" << end << endl;
		//for(int i=0; i<length;i++)
		//{
		//	cout << process[i] << endl;
		//}
	}

	
	
};

class FileIO{
	int beginning, end, length, requestsGenerator, interleavingGenerator;
	vector<Process> make_process;

public:
	FileIO(){
		
	}

	void readFile(){
		string line;
		ifstream myfile("input.txt");
		if(myfile.is_open())
		{
			while(getline(myfile,line))
			{
				//cout<<line<<'\n';
				vector<int> vect;


				stringstream ss(line);

				int i;

				while (ss >> i)
				{
					vect.push_back(i);

					if(ss.peek() == ',')ss.ignore();
					
				}

				for(i=0;i<vect.size();i++)
				{
					//cout<< "integer: " << i << endl;
					//cout << vect.at(i) << endl;

					if(i==0)
						beginning = vect.at(i);

					if(i==1)
						end = vect.at(i);

					if(i==2)
						length = vect.at(i);

					if(i==3)
						requestsGenerator = vect.at(i);

					if(i==4)
						interleavingGenerator = vect.at(i);

					make_process.push_back(Process(beginning,end,length,requestsGenerator,interleavingGenerator));
				
				}
				cout<<"FileIO check on values:"<<endl;
				cout << beginning << endl;
				cout << end << endl;
				cout << length<< endl;
				cout << requestsGenerator << endl;
				cout << interleavingGenerator << endl;

					
					
			}
			myfile.close();
		}

		else cout << "Unable to open file";

	}

	//request process object by order of when it was created
	Process return_process(int i){
		return make_process[i];
	}

	

};

int main(int argc, char** argv) {
	std::cout<<"Hello, World!"<<endl;
	FileIO f1;
	f1.readFile();

	//Process p1(5,100,30,1,1);
	//cout << p1.getBeginning() << endl;

	//cout << f1.return_process(0).getBeginning() << endl;

	//f1.return_process(0).printProcess();
/*
	cout << f1.return_process(0).getBeginning() << endl;
	cout << f1.return_process(0).getEnd(); << endl;
	cout << f1.return_process(0).getLength(); << endl;
	cout << f1.return_process(0).getRequestsGen(); << endl;
	cout << f1.return_process(0).getInterleavingGen(); << endl;
	*/

	cout << "Main check on values:"<< endl;
	cout << f1.return_process(0).getBeginning() << endl;
	cout << f1.return_process(0).getEnd() << endl;
	cout << f1.return_process(0).getLength() << endl;
	cout << f1.return_process(0).getRequestsGen() << endl;
	cout << f1.return_process(0).getInterleavingGen() << endl;

	return 0;
}
