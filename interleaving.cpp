
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
			gen = "sequential";
		}
		else
		{
			gen = "random";
		}
		
		cout<< length << " " << gen << " integers between " << beginning << " and " << end << endl;
		for(int i=0; i<length;i++)
		{
			cout << process[i];
			if(i<(length-1))
			{
				cout << ", ";
			}
		}
	}


/*
    vector<vector<string> > readFile(){
		vector<vector<string> > data;
        ifstream infile("input.txt");

        while(infile)
        {
            string s;
            if(!getline(infile, s)) break;

            istringstream ss(s);
            vector<string> record;

            while(ss)
            {
                string s;
                if(!getline(ss,s,',')) break;
                record.push_back(s);
            }

            data.push_back(record);
        }

        if(!infile.eof())
        {
            cerr << "Fooey!\n";
        }

        return data;
    }
*/
	
};

////////////////////////////////////////



//////////////////////////////////////////////////
int main(int argc, char** argv) {
	//std::cout<<"Hello, World!"<<endl;

	Process p1(5,100,30,1,1);
	Process p2(50,200,20,1,1);
	Process p3(10,100,50,1,1);

	

	if(p1.getRequestsGen()==1)
	{
		p1.sequentialGenerator();
		p2.sequentialGenerator();
		p3.sequentialGenerator();
	}
	
	
	else if(p1.getRequestsGen()==2)
	{
		p1.randomGenerator();
		p2.randomGenerator();
		p3.randomGenerator();
	}
	



	cout << "\nPrinting Process 1 of ";
	p1.printProcess();
	cout << "\n\nPrinting Process 2 of ";
	p2.printProcess();
	cout << "\n\nPrinting Process 3 of ";
	p3.printProcess();

	if(p1.getInterleavingGen() == 1)
	{
		cout << "\nSequential Interleaved Process:\n";
		p1.interleavingSequential();
		p2.interleavingSequential();
		p3.interleavingSequential();
	}

	else if(p1.getInterleavingGen()==2)
	{
		cout << "\nRandom Interleaved Process:\n";
		p1.interleavingRandom();
		p2.interleavingRandom();
		p3.interleavingRandom();
	}

	else{
		cout << "\nChosen interleaved option is unavailable.\n";
	}
	


	return 0;
}
