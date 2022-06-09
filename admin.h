

struct employee
{ 
	char ename[50];
	int ide;
	char email[30]; 
	char desig[30];
	char address[30];
	int salary;
	int age;
	long long int emno;
	struct employee*elink;
};
struct DEO
{
	char dname[50];
	char dmail[30];
	char daddress[30];
	long long int dmno;
	int dsalary;
	int dage;
	int duser;
	int dpass;
	int duserid;
	int dpassword;
	struct DEO *dlink;
};
void dispc(int);

void dispeh(); 
void ecreate();  
void einsert();
void eedit();
void deldeo();
int checkide(int);
void edel();
void dispe();
void deoregis();
void esearch();


char cch;
char ech; 
char dch;
struct employee *ecur,*etemp,*efirst=NULL,*elast=NULL;
struct DEO *dcur,*dtemp,*dfirst=NULL,*dlast=NULL;
struct employee *a[5]={NULL,NULL,NULL,NULL,NULL};
 int i,key,h;
void ecreate()
{
	   time_t t;  
         time(&t);
     
	ecur=(struct employee*)malloc(sizeof(struct employee));
	printf("\n\t\tEnter employee Id: ");
	scanf("%d",&ecur->ide);
	int en=checkide(ecur->ide);
	if(en==1)
	{

	   while(checkide(ecur->ide)==1)
	   {
		
	 	   printf("\n\t\tID already exists Enter another ID ");
		   scanf("%d",&ecur->ide);
	
	   }
    }
	printf("\n\t\tEnter employee Name:  ");
	scanf("%s",ecur->ename);
    printf("\n\t\tEnter employee Mobile No: ");
	scanf("%lli",&ecur->emno);  
    printf("\n\t\tEnter employee Mail Id: ");
	scanf("%s",ecur->email);
	printf("\n\t\tEnter designation of Employee ");
	scanf("%s",ecur->desig);
	printf("\n\t\tEnter  salary of Employee:  ");
	scanf("%d",&ecur->salary);
	printf("\n\t\tEnter Age of Employee  ");
	scanf("%d",&ecur->age);
	printf("\n\t\tEnter address:  ");
	scanf("%s",ecur->address);
	ecur->elink=NULL;
	efirst=ecur;  
	elast=ecur;
	a[h]=ecur;
	FILE *fpe;
	fpe=fopen("EmployeeData.txt","a");
	if(fpe==NULL)
	{
		printf("\n\t\tFile is empty");
	}
	else
	{
		fprintf(fpe,"%d %s %lli %s %s %d %d %s %s",ecur->ide,ecur->ename,ecur->emno,ecur->email,ecur->desig,ecur->salary,ecur->age,ecur->address,ctime(&t));
		printf("\n");
	}
	fclose(fpe);
}


void einsert()
{
    etemp=a[h];
	ecur=(struct employee*)malloc(sizeof(struct employee));
    
	   time_t t;  
         time(&t);
     
	int en;
    ecur=(struct employee*)malloc(sizeof(struct employee));
    printf("\n\t\tEnter employee id");
	scanf("%d",&ecur->ide);
	en=checkide(ecur->ide);
	if(en==1)
	{

	   while(checkide(ecur->ide)==1)
	   {
		
	 	   printf("\n\t\tID already exists Enter another ID ");
		   scanf("%d",&ecur->ide);
	
	   }
    }
	
	printf("\n\t\tEnter Employees' Name: ");
	scanf("%s",ecur->ename);
	

    printf("\n\t\t Enter Employees Mobile No: ");
	scanf("%lli",&ecur->emno);    
    
	printf("\n\t\tEnter Employees Mail Id: ");
	scanf("%s",ecur->email); 
	printf("\n\t\tEnter the designation of Employee: ");
	scanf("%s",ecur->desig);
	printf("\n\t\tEnter Salary of Employee ");
	scanf("%d",&ecur->salary);
	printf("\n\t\tEnter Age of Employee:  ");
	scanf("%d",&ecur->age);
	printf("\n\t\tEnter address ");
	scanf("%s",ecur->address);
	ecur->elink=NULL;
	//ecur->elink=NULL;
    while(etemp->elink!=NULL)
    {
   		etemp=etemp->elink;
    }
    etemp->elink=ecur;
	FILE *fpe;
	fpe=fopen("EmployeeData.txt","a");
	if(fpe==NULL)
	{
		printf("\n\t\tFile is empty");
	}
	else
	{
		fprintf(fpe,"%d %s %lli %s %s %d %d %s %s",ecur->ide,ecur->ename,ecur->emno,ecur->email,ecur->desig,ecur->salary,ecur->age,ecur->address,ctime(&t));
		
	}
	fclose(fpe);
	
}


int checkide(int b)
{
	   time_t t;  
         time(&t);
     
	FILE* fpe;
	fpe= fopen("EmployeeData.txt", "r");
    if (!fpe)
        printf("\n\t\tCan't open file\n"); 
	else 
	{
		rewind(fpe);
		char ebuffer[1024];
        int erow = 0;
        int ecolumn = 0;
        while (fgets(ebuffer,1024, fpe))
		{
			
            ecolumn = 0;
            erow++;
            char* evalue = strtok(ebuffer," ");
            while (evalue) 
			{
                if(ecolumn==0)
				{
                   if(b==atoi(evalue))
				   {
                    	return 1;
				   }
                }
                evalue = strtok(NULL," ");
                ecolumn++;
            }
            
        }
        
        fclose(fpe);
    }
    return 0;
} 
void eedit() 
{
	   time_t t;  
         time(&t);
     
	int emid,echoice;
	efirst=NULL;
	
	char che;
	FILE *fpe= fopen("EmployeeData.txt", "r");
    	char ebuffer[1024];
        int ecolumn = 0;
        while (fgets(ebuffer,1024,fpe)!=NULL)
        {
        	ecolumn=0;
        	char* evalue = strtok(ebuffer," ");
        	struct employee*newn=(struct employee*)malloc(sizeof(struct employee));
        	while(evalue)
        	{
        		if(ecolumn==0)
			    {
               	    newn->ide=atoi(evalue);
                }
                if(ecolumn==1)
			    {
               	    strcpy(newn->ename,evalue);
                }
                if(ecolumn==2)
				{
                     newn->emno=atoi(evalue);
                }
                if(ecolumn==3)
				{
               	    strcpy(newn->email,evalue);
                }
                if(ecolumn==4)
				{
                	strcpy(newn->desig,evalue);
				}
                if(ecolumn==5)
				{
             	    newn->salary=atoi(evalue);
                }
                if(ecolumn==6)
                {
                	newn->age=atoi(evalue);
				}
           	    if(ecolumn==7)
				{
               	    strcpy(newn->address,evalue);
           	    }
			    evalue = strtok(NULL," ");
	            ecolumn++;
	    }
		newn->elink=NULL;
	 	if(efirst==NULL)
	   {
	 		efirst=newn;
	    }
	    else
		{
		 	ecur=efirst;
			while(ecur->elink!=NULL)
			{
				ecur=ecur->elink;
			}
			ecur->elink=newn;
		}
        	
	}
	ecur=efirst;
	fclose(fpe);
		
	etemp = efirst; 
	printf("\nEnter the ID. of the employee whose info you want to change:");
    scanf("%d",&emid);
    while(etemp->ide!=emid)
   {
		etemp=etemp->elink;
	}
			printf("\n\t\t Data with employee ID %d Found !!\n",emid);
            printf("enter which info you want to change: \n 1->mobile number \n 2->Mail \n 3->Salary \n 4->Designation\n\t");
            scanf("%d",&echoice);
            switch(echoice)
            {
            	case 1:
            
              
                printf("\n\t\t Enter new Mobile No :");
	            scanf("%lli", &etemp->emno); 
  
                break;
                case 2:
           	      printf("\n\t\t Enter new mail ");
                  scanf("%s", etemp->email); 
		          break;
            	
               case 3:
                     printf("\n\t\t Enter new Salary "); 
              		 scanf("%d", &etemp->salary); 
			 	     break;  
			   case 4:
			   	     printf("\n\t\t Enter New Designation:");
            	     scanf("%s", etemp->desig  );
            	     break;
			}
   		etemp=efirst;
	FILE *fpen=fopen("EmployeeData.txt","w");
		while(etemp!=NULL)
		{
			fprintf(fpen,"%d %s %lli %s %s %d %d %s %s",etemp->ide,etemp->ename,etemp->emno,etemp->email,etemp->desig,etemp->salary,etemp->age,etemp->address,ctime(&t));
			printf("\n");
			etemp=etemp->elink;
		}
		
	fclose(fpen);
            
    printf("Updation Successful!!!\n");
}
void dispe()
{
     
	FILE *fpe;
		fpe=fopen("EmployeeData.txt","r");
		while(1)
		{
			ech=fgetc(fpe);
			if(ech==EOF)
	    		break;
	    	printf("%c",ech);
		}
}

/*
void edel()
{
         time_t t;  
         time(&t);
     
    struct employee *ecur;
    FILE *fpe, *fte; 
    int end;
    fpe = fopen("EmployeeData.txt","r");
    fte = fopen("Temp.txt","w");

    printf("\nEnter ID of employee to delete ");

    scanf("%d",&end);
    rewind(fpe);
    printf("red");
    while (!feof(fpe))
   {
        fscanf(fpe,"%d %s %lli %s %s %d %d %s %s",ecur->ide,ecur->ename,ecur->emno,ecur->email,ecur->desig,ecur->salary,ecur->age,ecur->address,ctime(&t));
        printf("re");
        if(ecur->ide!=end)
		{
            fprintf(fte,"%d %s %lli %s %s %d %d %s %s",ecur->ide,ecur->ename,ecur->emno,ecur->email,ecur->desig,ecur->salary,ecur->age,ecur->address,ctime(&t));
        }
    }

    fclose(fpe);
    fclose(fte);
    remove("EmployeeData.txt");
    rename("Temp.txt","EmployeeData.txt");
}*/

void edel()
{
	FILE *fptr1, *fptr2;
    char file1[] ="EmployeeData.txt";
    char file2[] ="file2.txt";
    char curr;
    int del, line = 0;
    printf("Please enter the line number you want to delete : ");
    scanf("%d", &del);
    fptr1 = fopen(file1,"r");
    fptr2 = fopen(file2, "w");
    curr = getc(fptr1);
    if(curr!=EOF) {line =1;}
    while(1){
      if(del != line)
        putc(curr, fptr2);
        curr = getc(fptr1);
        if(curr =='\n') line++;
        if(curr == EOF) break;
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("EmployeeData.txt");

    rename("file2.txt","EmployeeData.txt");
}
void deoregis()
{
	dcur=(struct DEO*)malloc(sizeof(struct DEO));
	printf("\n\t\tEnter DEO Name:  ");
	scanf("%s",dcur->dname); 
    printf("\n\t\tEnter DEO Mobile No: ");
	scanf("%lli",&dcur->dmno);  
    printf("\n\t\tEnter DEO Mail Id: ");
	scanf("%s",dcur->dmail);
	printf("\n\t\tEnter  salary of DEO  ");
	scanf("%d",&dcur->dsalary);
	printf("\n\t\tEnter Age of DEO  ");
	scanf("%d",&dcur->dage);
	printf("\n\t\tEnter address of DEO  ");
	scanf("%s",dcur->daddress);
	dcur->dlink=NULL;
	dfirst=dcur;  
	dlast=dcur;
	FILE *fpd;
	fpd=fopen("DEOData.txt","w");
	if(fpd==NULL)
	{
		printf("\n\t\tFile is empty");
	}
	else
	{
		fprintf(fpd," %s %lli %s %d %d %s",dcur->dname,dcur->dmno,dcur->dmail,dcur->dsalary,dcur->dage,dcur->daddress);
		printf("\n");
	}
	fclose(fpd);
	FILE *fpup;
	fpup = fopen("userpass.txt","w");
	int duser;
	int dpass;
	printf("enter username");
	scanf("%d", &duser);
	printf("enter password");
	scanf("%d", &dpass);
	{
		fprintf(fpup,"%d %d",duser, dpass);
		
	}
	
}

void deodisp()
{
	FILE *fpd;
		fpd=fopen("DEOData.txt","r");
		while(1)
		{
			dch=fgetc(fpd);
			if(dch==EOF)
	    		break;
	    	printf("%c",dch);
		}
}
 
void dispeh()
{
	  time_t t;  
         time(&t);
     
    printf("\n");
    for(i=0;i<5;i++)
    {
   		if(i==0)
   		{
		   printf("\nDeatils of employees of designation PHOTOGRAPHER");
		   etemp=a[i];
    		while(etemp!=NULL)
        	{
           		printf("%d %s %lli %s %s %d %d %s %s",etemp->ide,etemp->ename,etemp->emno,etemp->email,etemp->desig,etemp->salary,etemp->age,etemp->address,ctime(&t));
            	etemp=etemp->elink;
       		}
       	}
       	else if(i==1)
   		{
		   printf("\nDeatils of employees of designation VIDEOGRAPHER");
		   etemp=a[i];
    		while(etemp!=NULL)
        	{
           		printf("%d %s %lli %s %s %d %d %s %s",etemp->ide,etemp->ename,etemp->emno,etemp->email,etemp->desig,etemp->salary,etemp->age,etemp->address,ctime(&t));
            	etemp=etemp->elink;
       		}
       	}
       	else if(i==2)
   		{
		   printf("\nDeatils of employees of designation EDITOR");
		   etemp=a[i];
    		while(etemp!=NULL)
        	{
           		printf("%d %s %lli %s %s %d %d %s %s",etemp->ide,etemp->ename,etemp->emno,etemp->email,etemp->desig,etemp->salary,etemp->age,etemp->address,ctime(&t));
            	etemp=etemp->elink;
       		}
       	}
       	else if(i==3)
   		{
		   printf("\nDeatils of employees of designation DEO");
		   etemp=a[i];
    		while(etemp!=NULL)
        	{
           		printf("%d %s %lli %s %s %d %d %s %s",etemp->ide,etemp->ename,etemp->emno,etemp->email,etemp->desig,etemp->salary,etemp->age,etemp->address,ctime(&t));
            	etemp=etemp->elink;
       		}
       	}
       	else if(i==4)
   		{
		   printf("\nDeatils of employees of designation MANAGEMENT");
		   etemp=a[i];
    		while(etemp!=NULL)
        	{
           		printf("%d %s %lli %s %s %d %d %s %s",etemp->ide,etemp->ename,etemp->emno,etemp->email,etemp->desig,etemp->salary,etemp->age,etemp->address,ctime(&t));
            	etemp=etemp->elink;
       		}
       	}
	}
    

}

void esearch() 
{
	   time_t t;  
         time(&t);
     
	int emid,echoice;
	efirst=NULL;
	
	char che;
	FILE *fpe= fopen("EmployeeData.txt", "r");
    	char ebuffer[1024];
        int ecolumn = 0;
        while (fgets(ebuffer,1024,fpe)!=NULL)
        {
        	ecolumn=0;
        	char* evalue = strtok(ebuffer," ");
        	struct employee*newn=(struct employee*)malloc(sizeof(struct employee));
        	while(evalue)
        	{
        		if(ecolumn==0)
			    {
               	    newn->ide=atoi(evalue);
                }
                if(ecolumn==1)
			    {
               	    strcpy(newn->ename,evalue);
                }
                if(ecolumn==2)
				{
                     newn->emno=atoi(evalue);
                }
                if(ecolumn==3)
				{
               	    strcpy(newn->email,evalue);
                }
                if(ecolumn==4)
				{
                	strcpy(newn->desig,evalue);
				}
                if(ecolumn==5)
				{
             	    newn->salary=atoi(evalue);
                }
                if(ecolumn==6)
                {
                	newn->age=atoi(evalue);
				}
           	    if(ecolumn==7)
				{
               	    strcpy(newn->address,evalue);
           	    }
			    evalue = strtok(NULL," ");
	            ecolumn++;
	    }
		newn->elink=NULL;
	 	if(efirst==NULL)
	   {
	 		efirst=newn;
	    }
	    else
		{
		 	ecur=efirst;
			while(ecur->elink!=NULL) 
			{
				ecur=ecur->elink;
			}
			ecur->elink=newn; 
		}
        	
	}
	ecur=efirst;
	fclose(fpe);
		
	etemp = efirst; 
	printf("\nEnter the ID. of the employee whose info you want to find:");
    scanf("%d",&emid);
    while(etemp->ide!=emid)
   {
		etemp=etemp->elink;
	}
	printf("\n\t\t Data with employee ID %d Found !!\n",emid);
	printf("\n");
	printf("\nid : %d\nname : %s\nmobile number: %lli\nemail :%s\ndesignation : %s\nsalary : %d\nage : %d\naddress : %s",etemp->ide,etemp->ename,etemp->emno,etemp->email,etemp->desig,etemp->salary,etemp->age,etemp->address);
	
            
}

void deldeo()
{
	if(remove("DEOData.txt") == 0)
	{
	     printf("Deleted DEO Successfully");
    }
    
}
