//ÁÁÁÎ-02-18 Ôðîëîâ Ïàâåë Äåíèñîâè÷ 12 âàðèàíò
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <malloc.h>
using namespace std;

struct SPIS{
	struct Duge{
	int i, j,weight;
};
	Duge D;
	SPIS *next;
};
struct Versh{
	Versh *sled;
	char* vert;
};

class graf{
	protected:
	int flag,i,j,i_,j_,n,cnt,m,k_,k,count;int node,roads,vertSize;
	Versh *pbegin=NULL,*pcur=NULL,*plast=NULL;
	string path;
	char* v1;
	char* v2;
	char* weight;
	int **Matrix;
	int** Incident;int** Reach;int** Check;
	public:
		int Rabota(int node,int roads,string path);
		graf(){
			cout<<"i'm graf constructor\n";
		}
		~graf(){cout<<"\ni'm graf destructor";
		}
		
};

class Spisok:public graf{
	private:
		SPIS *ppred=NULL,*ptek=NULL,*pstart=NULL,*pawake=NULL;
		int number;SPIS *pnew=NULL;
		char* vertex;
	public:
		int Print(char c);
		int Change(char c);
		int AddDelete(char c);
		Spisok(int node,int roads,string path);
		~Spisok(){
			cout<<"\nI'm destruction itself"<<endl;
		}
		
		
};




int graf::Rabota(int node,int roads,string path){
	flag=0;cnt=0;vertSize=0;
	Matrix=new int*[node];	weight=new char[5];	v2=new char[5];	v1=new char[5];
	
	ifstream file(path.c_str());
	
	
	for (i=0;i<node;i++){
		Matrix[i]=new int[node];
	}
	
	while(!file.eof()){
		// cout<<first<<"   "<<second<<endl;
		if (flag==1){
			file.getline(v1,7,' ');      file.getline(v2,7,'\n');
			int first=atoi(v1);    int second = atoi(v2);
			for(i=0;i<node;i++){	
			for(j=0;j<node;j++){
				if(first==i+1  && second==j+1)
				{
				 *(*(Matrix+i)+j)=1;
				 break; 
				}
				else{	
					if(*(*(Matrix+i)+j)>100) 
					{*(*(Matrix+i)+j)=0;}}
				v2[i]='\n';
				}}}
		else{
		file.getline(v1,7,'\n');//cout<<start<<endl; 
		}
		if (v1[0]=='#'){flag++;}}
		
	cout<<"Matrix of Adjacency = "<<endl;
	for(i=0;i<node;i++){	
		for(j=0;j<node;j++){
			if (j<node-1){
				cout<<*(*(Matrix+i)+j)<<"  ";
			}
			else{
				cout<<*(*(Matrix+i)+j)<<endl;
			}}}
					
	file.clear();file.seekg(0);
	
	
	i=0;flag=0;
	while(v1[0]!='#'){
		vertSize++;
		pcur=new Versh;
		if(!pcur){
			cout<<"Goblins stole all of the data!!"<<endl;
			return 0;
		}
		pcur->vert=new char[5];
		file.getline(v1,7,' ');   if(v1[0]=='#'){break;}     file.getline(pcur->vert,7,'\n'); 
			
		if(flag==0){
			plast=pcur;
			pbegin=pcur;
			pcur->sled=pcur;    
			flag=1;
			
			//p
		}
		else{
			if (flag==1){
				pbegin->sled=pcur;
				pcur->sled=pbegin;
				plast->sled=pcur;
				plast=pcur;
				flag=2;
			}
			else{
				pcur->sled=pbegin;
				plast->sled=pcur;
				plast=pcur;
			}
		}
   
        i++;
	}
	vertSize--;
	file.clear();file.seekg(0);flag=0;

	
	
	Incident=(int**)malloc(roads*sizeof(int*));
	for (i=0;i<roads;i++){
		Incident[i]=(int*)malloc((node+1)*sizeof(int));
	}

	
	
	
	while(!file.eof()){
		if (flag==1){
			
			for(i=0;i<roads;i++){	
			file.getline(v1,7,' ');      file.getline(v2,7,' ');  	file.getline(weight,7,'\n');
			int first=atoi(v1);    int second = atoi(v2); int third = atoi(weight);
			for(j=0;j<=node;j++){
				if (j==0){  *(*(Incident+i)+j)=third;continue;  }
				if(j==second && j==first){
					*(*(Incident+i)+j)=2;continue;
				}
				
				if(j==first)
				{
				 *(*(Incident+i)+j)=1;continue;
				}
				
				
				if (j==second)
				{	
					*(*(Incident+i)+j)=-1;continue;
			    }
				else{
					*(*(Incident+i)+j)=0;
				}}}
			file.getline(v1,7,'\n');
				}
		else{
		file.getline(v1,7,'\n');//cout<<start<<endl; 
		}
		if (v1[0]=='#'){flag++;}
		}
		
		
	cout<<endl<<"Incident Matrix"<<endl;
	/* cout<<"Wt ";
	 for (i=0;i<node;i++){
	 	//cout<<"Incid["<<i+1<<"] = ";
	 	cout<<Incid[i]<<" ";
	 }
	 cout<<endl;*/
	 
	 
	 for(i=0;i<roads;i++){
	 	for(j=0;j<=node;j++){
	 		if(j==0 && Incident[i][j]>9){
	 			cout<<Incident[i][j]<<" ";continue;
			 }
	 		if(j==node){
	 		cout<<Incident[i][j]<<endl;}
	 		else{
	 			if(Incident[i][j+1]==-1){
	 				cout<<Incident[i][j]<<" ";
			 		}
			 	else{
			 	cout<<Incident[i][j]<<"  ";
				 }
		 }
	 }}
		
		
	k=0;
	Reach=(int**)malloc((node*sizeof(int*)));
	for (i=0;i<node;i++){
		Reach[i]=(int*)malloc(node*sizeof(int));
	}
	
    for (i=0;i<node;i++){
    	for(j=0;j<node;j++){
    		if (i==j){
    			*(*(Reach+i)+j)=1;
			}
			else{
				if (*(*(Matrix+i)+j)==1)    {    *(*(Reach+i)+j)=1;  	}
				else    {  *(*(Reach+i)+j)=0;  }
			}
		}
	}
	for(k=0;k<node;k++){
		for(i=0;i<node;i++){
			for(j=0;j<node;j++){
				if(*(*(Reach+i)+j)==0){
					if(*(*(Reach+k)+j) && *(*(Reach+i)+k)){
						*(*(Reach+i)+j)=1;
					}
				}
			}
		}
	}
	cout<<endl<<"Reach Matrix"<<endl;
	for (i=0;i<node;i++){
    	for(j=0;j<node;j++){
    	if(j<node-1){
    		cout<<*(*(Reach+i)+j)<<" ";
		}
		else{
			cout<<*(*(Reach+i)+j)<<endl;
			
		}}}
		
	flag=0;
	

	for (i=0;i<node;i++){
		for (j=0;j<node;j++){
			if (i==j){
				*(*(Reach+i)+j)=0;continue;
			}}}
			
	
	
	
	Check;
	Check=(int**)malloc((node*sizeof(int*)));
	for(i=0;i<node;i++){
		Check[i]=(int*)malloc(node*sizeof(int));
	}
	for(i_=0;i_<node;i_++){
		
		for(j_=0;j_<node;j_++){
			
			for (k_=0;k_<node;k_++){
				
				if(*(*(Matrix+i_)+j_)==1){
					if ( *(*(Reach+i_)+k_) ==1 && *(*(Matrix+k_)+j_) ==1 ) {
						*(*(Matrix+i_)+j_)=0;
						for (m=0;m<node;m++){
				    	for (n=0;n<node;n++){
				    		if (m==n){
				    			*(*(Check+m)+n)=1;
							}
							else{
								if (*(*(Matrix+m)+n)==1)    {    *(*(Check+m)+n)=1;  	}
								else    {  *(*(Check+m)+n)=0;  }
							}	}	}
						
						for(k=0;k<node;k++){
							for(i=0;i<node;i++){
								for(j=0;j<node;j++){
									if(*(*(Check+i)+j)==0){
										if(*(*(Check+k)+j) && *(*(Check+i)+k)){
											*(*(Check+i)+j)=1;
															}	}	}	}	}
					/*if( !(  *(*(Check+i_)+j_)==1 ) ){
						*(*(Matrix+i_)+j_)=1;
					}*/}
				
				
				
				
				}
			}
		}
	}
	for(i=0;i<node;i++){
		free(Check[i]);
	}
	free(Check);
			
				
	cout<<"Updated Matrix of Adjacency = "<<endl;
	for(i=0;i<node;i++){	
		for(j=0;j<node;j++){
			if (j<node-1){
				cout<<*(*(Matrix+i)+j)<<"  ";
			}
			else{
				cout<<*(*(Matrix+i)+j)<<endl;
			}}}
			
	for (i=0;i<node;i++){
    	for(j=0;j<node;j++){
    		if (i==j){
    			*(*(Reach+i)+j)=1;
			}
			else{
				if (*(*(Matrix+i)+j)==1)    {    *(*(Reach+i)+j)=1;cnt++;  	}
				else    {  *(*(Reach+i)+j)=0;  }
			}
		}
	}
	
	for(k=0;k<node;k++){
		for(i=0;i<node;i++){
			for(j=0;j<node;j++){
				if(*(*(Reach+i)+j)==0){
					if(*(*(Reach+k)+j) && *(*(Reach+i)+k)){
						*(*(Reach+i)+j)=1;
					}
				}
			}
		}
	}
	
	
	
	cout<<endl<<"Reach Matrix"<<endl;
	for (i=0;i<node;i++){
    	for(j=0;j<node;j++){
    	if(j<node-1){
    		cout<<*(*(Reach+i)+j)<<" ";
		}
		else{
			cout<<*(*(Reach+i)+j)<<endl;
			
		}}}
		
		
	for(i=0;i<node;i++){
		free(Reach[i]);
	}
	free(Reach);//file.close();
	return cnt;
}







Spisok::Spisok(int node,int roads,string path){
	cout<<"I'm construction itself"<<endl;
	Rabota(node,roads,path);
	
	m=0;	
	while(m<cnt){
		ptek=new SPIS;
		if(!(ptek))
			{
    		cout<<"There is no place to put data in,try to pray gods or something else but it exactly won't help"<<endl;
    		}
    	else{
    		ptek->D.i;
    		ptek->D.j;
    		ptek->D.weight;
    	if (m==0){
    		pstart=ptek;
    		ppred=ptek;
		}
		else{
			if (m==1){
			pstart->next=ptek;
			ptek->next=pstart;
			ppred->next=ptek;
			ppred=ptek;}
			else{
				ptek->next=pstart;
				ppred->next=ptek;
				ppred=ptek;
			}
		}
		
		m++;
	}}
	pawake=ppred;
	ptek=pstart;i=0;
	while(m>i){
		ptek=ptek->next;
    	ppred=ptek;
    	i++;
	}
	m=1;
	ptek=pstart;
	while(m<cnt){
	for(i=0;i<node;i++){
		for (j=0;j<node;j++){
			if(*(*(Matrix+i)+j)==1 && i!=j){
				for(k=0;k<roads;k++){
	
					if( *(*(Incident+k)+i+1) == 1 && *(*(Incident+k)+j+1) ==-1 ){
						ppred=ptek;
						ptek=ptek->next;
						ptek->D.i=i+1;
						ptek->D.j=j+1;
						ptek->D.weight=*(*(Incident+k));m++;
						break;
					}}}}}}
	m=0;ptek=pstart;
	cout<<"List of roads"<<endl;
	cout<<"  ptek   i j wt   ppred"<<endl;
	
	while(cnt>m){
		cout<<ptek<<" "<< ptek->D.i<<"  "<<ptek->D.j<<"  "<<ptek->D.weight<<" "<<ppred<<endl;
			ppred=ptek;
			ptek=ptek->next;
		
		m++;
	}
	ppred=ptek;
	cout<<"Vertex List\n";
	pcur=pbegin;i=0;
		while(node>i){
			cout<<"pcur = "<<pcur<<" Vertex = "<<pcur->vert<<" plast"<<plast<<endl;
			if(i<node-1){
				plast=pcur;
				pcur=pcur->sled;}
			i++;
		}	
}


	

int Spisok::AddDelete(char c){
	flag=0;
	switch(int(c)-48){
		case 1:
			flag=0;
			ptek=pstart;
			pnew=new SPIS;
			pnew=(struct SPIS*)malloc(sizeof(struct SPIS));
			if(!pnew){
				cout<<"Your ex take all your data!!!"<<endl;
				return 0;
			}
			
			cout<<"Enter the beggining of the road = ";
			cin>>pnew->D.i;
			
			for(i=0;i<vertSize;i++){
				pcur->vert[0]=' ';
				if (pnew->D.i==atoi(pcur->vert)){
					flag=1;
				}
				pcur->vert[0]='v';
				plast=pcur;
				pcur=pcur->sled;
			}
			if(flag==0){cout<<"No such vertex";return 0;}
			flag=0;
			
			cout<<"Now the end = ";
			cin>>pnew->D.j;
			
			for(i=0;i<vertSize;i++){
				pcur->vert[0]=' ';
				if (pnew->D.j==atoi(pcur->vert)){
					flag=1;
				}
				pcur->vert[0]='v';
				plast=pcur;
				pcur=pcur->sled;
			}
			if(flag==0){cout<<"No such vertex"<<endl;return 0;}
			flag=0;
			cout<<"Now enter the weight = ";
			cin>>pnew->D.weight;
			
			ppred=ptek->next;
			ptek->next=pnew;
			ptek=pnew;
			ptek->next=ppred;
			cnt++;i=0;
			ppred=pawake;
			ptek=pstart;
			break;
	case 2:
			ptek=pstart;
			i=1;
			cout<<"Enter the number of road,which you want to delete = ";
			cin>>number;
			if(!number){
				cout<<"Programm stopped!";
				return 1;
			}
			if(number>=cnt+1){
			cout<<"No way!!!"<<endl;
			return 0;}
			cout<<endl;
			while(number>i){
				ppred=ptek;
				ptek=ptek->next;
				i++;
			}
			if(ptek==pstart){
				pstart=pstart->next;
				ptek=ppred;
				ptek->next=pstart;
			}
			else{
				if(ptek==pawake){
					pawake=ppred;
					pawake->next=pstart;
					ptek=pawake;
				}
				else{
				ppred->next=ptek->next;
				ptek=ppred;
			}}
			ppred=pawake;
			ptek=pstart;
			i=0;cnt--;
			if (cnt==0){
				cout<<"I've told you!";return 1;
			}
			break;
	case 3:
			cout<<"Name new vertex('v'+number) = ";
			cin>>v1;
			pcur=pbegin;flag=0;
			for(i=1;i<vertSize;i++){
				if(strcmp(v1,pcur->vert)==0){
					flag=1;
				}
				plast=pcur;
				pcur=pcur->sled;
			}
			if (flag==1){cout<<"Such vertex exist!!";return 0;}
				

			plast=pcur;
			pcur=new Versh;
			
			if(!pcur){
				cout<<"No data!!!Come next week."<<endl;
				return 0;
			}
			pcur=(struct Versh*)malloc(sizeof(struct Versh));
			pcur->vert=new char[5];
			strcpy(pcur->vert,v1);
			if (pcur->vert[0]!='v'){
				cout<<"Error";pcur=pbegin;return 0;
			}
			pcur->sled=pbegin;
			plast->sled=pcur;vertSize++;
			pcur=plast;
			break;
	case 4:
		plast=pcur;
		pcur=pbegin;
		cout<<"What vertex do ypu want to delete? input it number(without 'v')  = ";
		cin>>number;
		if(!number){
				cout<<"Programm stopped!";
				return 1;
			}
		flag=0;
		for(i=0;i<vertSize;i++){
				pcur->vert[0]=' ';
				if (number==atoi(pcur->vert)){
					m=i;
					flag=1;
					pcur->vert[0]='v';
					strcpy(v1,pcur->vert);
				}
				
				pcur->vert[0]='v';
				plast=pcur;
				pcur=pcur->sled;
			}
		if (flag==0){
			cout<<"No such vertex!";return 0;
		}	
		pcur=pbegin;
		for(i=0;i<m;i++){
				plast=pcur;
				pcur=pcur->sled;
			}
		plast->sled=pcur->sled;
		if (pcur==pbegin){
			pbegin=plast->sled;
		}
		pcur=plast;
		pcur=pbegin;vertSize--;
		if(vertSize==0){
					cout<<"I've told you!";return 1;
				}
		ppred=pawake;
		ptek=pstart;k=0;count=0;
		
		while(k<cnt){
			if(number==ptek->D.i || number==ptek->D.j){
					if(count>=cnt){
					cout<<"I've told you!'";cnt=cnt-count;return 1;
				}
					count++;
					if(k==0){
						pstart=pstart->next;
						ptek=ppred;
						ptek->next=pstart;
						ppred=ptek;
						ptek=ptek->next;
						continue;
					}
					if(k==cnt-1){
						pawake=ppred;
						pawake->next=pstart;
						ptek=pawake;
						}
					else{
						ppred->next=ptek->next;
						ptek=ppred;
						}}
			k++;
			ppred=ptek;
			ptek=ptek->next;
		}
		
		cnt=cnt-count;
		k=0;
			pcur=plast;
			
		break;	//ptek
	}}
	
	

int Spisok::Change(char c){
	switch(int(c)-48){
		case 5:
			plast=pcur;
			pcur=pbegin;
			cout<<"What vertex do you want to change? input it number(without 'v')  = ";
			cin>>number;
			if(!number){
				cout<<"Programm stopped!";
				return 1;
			}
			flag=0;
			for(i=0;i<vertSize;i++){
					pcur->vert[0]=' ';
					if (number==atoi(pcur->vert)){
						m=i;
						flag=1;
						pcur->vert[0]='v';
					}
					
					pcur->vert[0]='v';
					plast=pcur;
					pcur=pcur->sled;
				}
			if (flag==0){
				cout<<"No such vertex!";return 0;
			}
			
			cout<<"Rename that vertex ('v'+number) = ";
			cin>>v1;
			if (v1[0]!='v'){
				cout<<"Error";return 0;
			}
			flag=0;
			pcur=pbegin;
			for(i=0;i<vertSize;i++){
					if (strcmp(v1,pcur->vert)==0){
						flag=1;}
					plast=pcur;
					pcur=pcur->sled;}
					
			pcur=pbegin;
			for(i=0;i<m;i++){
				plast=pcur;
				pcur=pcur->sled;
			}
			pcur->vert[0]=' ';n=atoi(pcur->vert);pcur->vert[0]='v';//n-íà÷àëüíàÿ âåðøèíà
			
			if (flag==1){
					cout<<"such vertex is already exist!!!";return 0;
			}
			else{strcpy(pcur->vert,v1);
			pcur->vert[0]=' ';k=atoi(pcur->vert);pcur->vert[0]='v';//k-íîâàÿ âåðøèíà
			}	
			if (pcur==pbegin){
				pbegin=pcur;
			}
			ptek=pstart;
			for (i=0;i<cnt;i++){
				
				if(n==ptek->D.i){
					ptek->D.i=k;
				}
				if(n==ptek->D.j){
					ptek->D.j=k;
				}
				ppred=ptek;
				ptek=ptek->next;
			}
			pcur=plast;
			break;
		case 6:
			ptek=pstart;
			i=1;
			cout<<"Enter the number of road,which you want to reload = ";
			cin>>number;
			if(!number){
				cout<<"Programm stopped!";
				return 1;
			}
			if(number>=cnt+1){
			cout<<"No way!!!"<<endl;
			return 0;}
			cout<<endl;
			while(number>i){
				ppred=ptek;
				ptek=ptek->next;
				i++;
			}
			cout<<"Now enter the weight = ";
			cin>>ptek->D.weight;
			if(ptek==pstart){
				pstart=ptek;
			}
			else{
				if(ptek==pawake){
					pawake=ptek;
				}
			}
			
			break;
		case 7:
			ptek=pstart;
			i=1;
			cout<<"Enter the number of road,which you want to redirect = ";
			cin>>number;
			if(!number){
				cout<<"Programm stopped!";
				return 1;
			}
			if(number>=cnt+1){
			cout<<"No way!!!"<<endl;
			return 0;}
			while(number>i){
				ppred=ptek;
				ptek=ptek->next;
				i++;
			}
			i=ptek->D.i; j=ptek->D.j;
			ptek->D.i=j; ptek->D.j=i;
			ppred=pawake;
			ptek=pstart;
				
	}
}


int Spisok::Print(char c){
	switch(int(c)-48){
		case 8:
			ppred=pawake;
			ptek=pstart;
			cout<<"  ptek   i j wt   ppred"<<endl;k=0;
			while(cnt>k){
				cout<<ptek<<" "<< ptek->D.i<<"  "<<ptek->D.j<<"  "<<ptek->D.weight<<" "<<ppred<<endl;
				ppred=ptek;
				ptek=ptek->next;k++;
			}
			break;
		case 9:
			plast=pcur;
			pcur=pbegin;
			cout<<"  pcur   vert   pnext"<<endl;
			for(i=0;i<vertSize;i++){
				cout<<pcur<<" "<<pcur->vert<<" "<<pcur->sled<<endl;
				plast=pcur;
				pcur=pcur->sled;
			}
			break;
}}

int main(){
	cout<<"--Hello world,my name is Paul!I'm glad to represent you my creation!-----------"<<endl<<"Lead the following instructions with all attentions and this programm will work.";
	cout<<endl<<"---------------------------Have fun!!!!-----------------------------------------\n\n\n\n\n";
	string path;char *stroka=new char[5];SPIS *pstart;
	int i=0,j=0,nodes=0,flag=0,roads=0,result;
	char c;
	cout<<"input the file name(no format) = ";
	getline(cin,path);
	path=path+".tgf";
	ifstream file(path.c_str());
	if(!file.is_open()){
		cout<<"shit";
		return 0;
	}
	while(!file.eof())
	{   if (stroka[0]=='#'){
			flag++;
		}
		file.getline(stroka,10,'\n');cout<<stroka<<endl;
		if (flag==0){nodes++;}
		else{roads++;}
		
	}
	roads--;nodes--;
	cout<<"Number of nodes = "<<nodes<<" number of roads = "<<roads<<endl;
	file.clear();
	file.seekg(0);
	Spisok g(nodes,roads,path);
	
	
	
	while(c>='1' || c<='9'){
	cout<<endl<<endl<<"\nWhat do you want to do with list?"<<endl;
	cout<<"\n\n1.Add new roads.\n2.Delete roads.\n3.Add Vertex.\n4.Delete vertex. \n5.Change name(vertex).\n6.Change weight(road).\n7.Change direction.\n8.Print Roads List\n9.Print Vertex List\n";
	cout<<"Press any other key to pay respects to the programm\nNote: Do not delete all the roads or vertex in the list,it will cause problems!!\n" ;
		cin>>c;
	cout<<"\n\n";
    switch(int(c)-48){
    	case 1:
    		result=g.AddDelete(c);break;
    	case 2:
    		result=g.AddDelete(c);
			break;
    	case 3:
    		result=g.AddDelete(c);break;
    	case 4:
    		result=g.AddDelete(c);
			break;
		case 5:
			result=g.Change(c);break;
		case 6:
			result=g.Change(c);break;
		case 7:
			result=g.Change(c);break;
		case 8:
			result=g.Print(c);break;
		case 9:
			result=g.Print(c);break;
    	default:
    		return 0;	break;
	}
	if (result==1){
    			return 0;
			}
	
	}
	return 0;
}

