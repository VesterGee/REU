
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/////////////////////////////////////////
class Process{
	int beginning, end, length, requestsGenerator, interleavingGenerator;
	vector<int> process;
public:
	Process(int beginning, int end, int length, int requestsGenerator, int interleavingGenerator){
		this->beginning = beginning;
		this->end = end;
		this->length = length;
		this->requestsGenerator = requestsGenerator;
		this->interleavingGenerator = interleavingGenerator;
	}
	
	void addRequest(int newNum){
		process.push_back(newNum);
	}

	void randomGenerator(){
		int random;
		for(int i = 0; i<length; i++)
		{
			random = rand() % (end-beginning) + beginning;
			cout << random << endl;
			addRequest(random);
		}
		
	}

	void sequentialGenerator(){

		int j = beginning;
		int end_condition = end;
		for(int i = 0; i<length; i++, j++)
		{
			if(end_condition==j)
			{
				j=beginning;
				//end_condition = end_condition + beginning;
			}
			cout << j << endl;
			addRequest(j);
		}
	}
	



	void interleavingSequential(){
		int random1 = rand() % (length - 1);
		int random2 = rand() % (length) + random1;
		for(int i=random1; i<random2;i++)
		{
			cout << process[i];
			if(i<(length-1))
			{
				cout << ", ";
			}
		}
	}

	void interleavingRandom(){
		int random1 = rand() % (length - 1);
		int random2 = rand() % (length) + random1;
		int random_interval = rand() % 5;


		for(int i=random1; i<random2; random1 = random1 + random_interval)
		{
			cout << process[i];
			if(i<(length-1))
			{
				cout << ", ";
			}
			random_interval = rand() % 5;
		}
	}

	void printValues()
	{
		int out;
		cout << "\nPrinting values in process" << endl;
		out = beginning;
		cout << out << endl;
		out = end;
		cout << out << endl;
		out = length;
		cout << out << endl;
		out = requestsGenerator;
		cout << out << endl;
		out = interleavingGenerator;
		cout << out   << endl;
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
		string gen;
		if(requestsGenerator==1)
		{
			gen = "random";
		}
		else
		{
			gen = "sequential";
		}
		
		cout<< length << " " << gen << " integers between " << beginning << " and " << end << endl;
		for(int i=0; i<5;i++)
		{
			cout << process[i];
			
			if(i<(length-1))
			{
				cout << ", ";
			}
			
		}
	}

	void writeFileProcess(){
		int data;
		ofstream outfile;
		outfile.open("trace-3-.");

		cout << "Writing to the file" << endl;
		
		for(int i = 0; i < length; i++)
		{
			data = process[i];
			outfile << data << endl;
			//outfile << "," << endl;
		}

		outfile.close();
	}



	
};

////////////////////////////////////////

class FileIO{
	int beginning, end, length, requestsGenerator, interleavingGenerator;
	vector<Process> make_process;

public:
	FileIO(){
		
	}

	void readFile(){
		beginning = 0;
		end = 0;
		length = 0;
		requestsGenerator = 0;
		interleavingGenerator = 0;
		
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

					/*
					beginning = std::stoi(beginning, nullptr);
					end = std::stoi(end, nullptr);
					length = std::stoi(length, nullptr);
					requestsGenerator = std::stoi(requestsGenerator, nullptr);
					interleavingGenerator = std::stoi(interleavingGenerator, nullptr);
					*/
					
				
				}

				make_process.push_back(Process(beginning,end,length,requestsGenerator,interleavingGenerator));
				/*
				cout<<"FileIO check on values:"<<endl;
				cout << beginning << endl;
				cout << end << endl;
				cout << length<< endl;
				cout << requestsGenerator << endl;
				cout << interleavingGenerator << endl;
				*/
					
					
			}
			myfile.close();
		}

		else cout << "Unable to open file";

	}

	//request process object by order of when it was created
	Process return_input(int i){
		return make_process[i];
	}

	


	//time to write file
	void writeFile()
	{
		char data[100];
		ofstream outfile;
		outfile.open("trace-3-.");

		cout << "Writing to the file" << endl;
		cout << "Enter your name: ";
		cin.getline(data,100);

		outfile << data << endl;

		cout << "Enter your age: ";
		cin >> data;
		cin.ignore();

		outfile << data << endl;

		outfile.close();


	}

	

};

//////////////////////////////////////////////////
int main(int argc, char** argv) {
	std::cout<<"Hello, World!"<<endl;

	FileIO f1;
	f1.readFile();
	//f1.writeFile();
	//f1.return_process(0).printValues();




/*
	Process p1(5,100,30,1,1);
	Process p2(50,200,20,1,1);
	Process p3(10,100,50,1,1);
*/
	if(f1.return_input(0).getRequestsGen()==1)
	{
		cout << "\nRandom Generator selected" << endl;
		f1.return_input(0).randomGenerator();
	}

	else if(f1.return_input(0).getRequestsGen()==2)
	{
		cout << "\nSequential Generator selected" << endl;
		f1.return_input(0).sequentialGenerator();
	}


	//cout << "\nPrinting Process 1 of ";
	f1.return_input(0).writeFileProcess();



	return 0;
}
