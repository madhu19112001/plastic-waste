struct customer
{
	char cname[50];
	int idc;
	char cmail[30];
	char type[10];
	char status[15];
	int copies,cost;
	long long int cmno;
	struct customer *clink,*rchild,*lchild;
};
//void ccreate();
void cinsert();
void cedit();
int checkidc(int);
int price=200;
void move( int);
void dispc(int);
void csearch();
int count();
void peek();
void dequeue();
int queuecheckid(int );
struct customer *getNode(int );
char chc;
struct customer *ccur,*ctemp,*cfirst=NULL,*clast=NULL;
struct customer *root;
void fordelay(int j) 
 {
   int i,k;
    for(i=0;i<j;i++)
         k=i;
 }
 



void cinsert()
{
	   time_t t;  
         time(&t);
     
	int n,choice,x,y,z;
    ccur=(struct customer*)malloc(sizeof(struct customer));
    printf("\n\t\tEnter customer id");
	scanf("%d",&ccur->idc);
	
    y=count();
    if(y!=0)
    {
    		while(queuecheckid(ccur->idc)==1)
      		{
      			printf("\n\t\tID already exists Enter another ID ");
		  		scanf("%d",&ccur->idc);
			}
      	
	}
	

	n=checkidc(ccur->idc);
	if(n==1)
	{

	   while(checkidc(ccur->idc)==1)
	   {
		
	 	   printf("\n\t\tID already exists Enter another ID ");
		   scanf("%d",&ccur->idc);
	
	   }
     }
	
	
	
	printf("\n\t\tEnter Customer's' Name :");
	scanf("%s",ccur->cname);
	

    printf("\n\t\t Enter Customer's Mobile No :");
	scanf("%lli",&ccur->cmno);    
    
	printf("\n\t\tEnter Customer's Mail Id :");
	scanf("%s",ccur->cmail);
	printf("\n\t\tEnter the type of photo ordered :");
	scanf("%s",ccur->type);
	printf("\n\t\tEnter No of Sheets required(Each Sheet contains 8 copies): ");
	scanf("%d",&ccur->copies); 
	printf("\n\t\tEnter status ");
	scanf("%s",ccur->status);
	if(cfirst==NULL)
	{
		ccur->clink=NULL;
		cfirst=ccur; 
		clast=ccur;
	}
	else
	{
		ccur->clink=NULL;
		clast->clink=ccur; 
		clast=ccur;
	}
	//ccur->clink=NULL;
//	clast->clink=ccur; 
//	clast=ccur;
	x=count();
	if(x==3)
	{
		peek();
	}
	else if(x<3)
	{
		printf("\nDo you want to write into the file..\n1->yes\n2->No");
    	scanf("%d",&choice);
	    if(choice==1)
	    {
			FILE *fpc;
			fpc=fopen("Processing.txt","a");
        	if(fpc==NULL)
			{
				printf("\n\t\tFile is empty"); 
			}
			else
			{
				 
				//ctemp=cfirst;
				while(cfirst!=NULL)
				{
					//ctemp=cfirst;
					fprintf(fpc,"\n%d %s %lli %s %s %d Rs.%d %s %s",cfirst->idc,cfirst->cname,cfirst->cmno,cfirst->cmail,cfirst->type,cfirst->copies,cfirst->copies*price,cfirst->status,ctime(&t));
					cfirst=cfirst->clink;
		
				}
				dequeue();
			
			}
			fclose(fpc);
			
    	}
    	else
    	{
    		printf("\nDetails will be entered into the file when queue is full");
		}
	    
	}

}

int checkidc(int a)
{
	   time_t t;  
         time(&t);
     
	FILE* fpc;
	fpc= fopen("Processing.txt", "r");
    if (!fpc)
        printf("\n\t\tCan't open file\n"); 
	else 
	{
		rewind(fpc);
		char buffer[1024];
        int row = 0;
        int column = 0;
        while (fgets(buffer,1024, fpc))
		{
			
            column = 0;
            row++;
            char* value = strtok(buffer," ");
            while (value) 
			{
                if(column==0)
				{
                   if(a==atoi(value))
				   {
                    	return 1;
				   }
                }
                value = strtok(NULL," ");
                column++;
            }
            
        }
        
        fclose(fpc);
    }
    return 0;
} 

void cedit() 
{
	   time_t t;  
         time(&t);
     
	int cuid,choice;
	cfirst=NULL;
	char chc;
	FILE *fpc= fopen("Processing.txt", "r");
    	char buffer[1024];
        int column = 0;
        while (fgets(buffer,1024,fpc)!=NULL)
        {
        	column=0;
        	char* value = strtok(buffer," ");
        	struct customer *newn=(struct customer *)malloc(sizeof(struct customer));
        	while(value)
        	{
        		if(column==0)
			    {
               	    newn->idc=atoi(value);
                }
                if(column==1)
			    {
               	    strcpy(newn->cname,value);
                }
                if(column==2)
				{
                     newn->cmno=atoi(value);
                }
                if(column==3)
				{
               	    strcpy(newn->cmail,value);
                }
                if(column==4)
				{
                	strcpy(newn->type,value);
				}
                if(column==5)
				{
             	    newn->copies=atoi(value);
                }
           	    if(column==7)
				{
               	    strcpy(newn->status,value); 
           	    }
			    value = strtok(NULL," ");
	            column++;
	       }
		newn->clink=NULL;
	 	if(cfirst==NULL)
	   {
	 		cfirst=newn;
	    }
	    else
		{
		 	ccur=cfirst;
			while(ccur->clink!=NULL)
			{
				ccur=ccur->clink;
			}
			ccur->clink=newn;
		}
        	
	}
	ccur=cfirst;
	fclose(fpc);
	int c=0;	
	ctemp = cfirst;
	printf("\nEnter the ID. of the customer whose info you want to change:");
    scanf("%d",&cuid);
    while(ctemp!=NULL)
   {
		if(ctemp->idc==cuid)
		{
			c++;
			break;
		}
		else
		{
			ctemp=ctemp->clink;
		}
   }
   if(c==1)
   {
   	    printf("\nId found");
   	    printf("enter which info you want to change: \n 1->Type of Photo \n 2->Mail \n 3->No of Sheets\n\t");
            scanf("%d",&choice);
            switch(choice)
            {
            	case 1:
                   printf("\n\t\t Enter new type :");
	               scanf("%s", ctemp->type); 
                   break;
                case 2:
           	      printf("\n\t\t Enter new mail ");
                  scanf("%s", ctemp->cmail); 
		          break;	
               case 3:
                     printf("\n\t\t Enter new no of Sheets: "); 
              		 scanf("%d", &ctemp->copies); 
			 	     break;
            	  
            	
			}
   		ctemp=cfirst;
		FILE *fpch=fopen("Processing.txt","w");
		while(ctemp!=NULL)
		{
			fprintf(fpch,"\n%d %s %lli %s %s %d Rs.%d %s %s",ctemp->idc,ctemp->cname,ctemp->cmno,ctemp->cmail,ctemp->type,ctemp->copies,ctemp->copies*price,ctemp->status,ctime(&t));
			
			ctemp=ctemp->clink;
		}
		
		fclose(fpch);
            
   		 printf("Updation Successful!!!\n");
   }
   else
   {
   	   printf("\nId not found,..Enter correct Id");
   }
			
            
}
void move(int cid)
{
 	     time_t t;  
         time(&t);
      
    struct customer * ctemp = cfirst;
    while(ctemp!=NULL){
        
        if(ctemp->idc==cid)
		{
            printf("Data with Customer ID %d Found !!\n",cid);
            printf("Enter new Status ");
            scanf("%s", ctemp->status); 
            
            FILE *fpc;
			fpc=fopen("Delivered.txt","a");
			if(fpc==NULL)
			{
				printf("\nFile is empty");
			}
			else
			{
				fprintf(fpc,"\n%d %s %lli %s %s %d Rs.%d %s %s",ctemp->idc,ctemp->cname,ctemp->cmno,ctemp->cmail,ctemp->type,ctemp->copies,ctemp->copies*price,ctemp->status,ctime(&t));
			}
			fclose(fpc);
            
            printf("Updation Successful!!!\n");
            return;
        }
        ctemp = ctemp->clink;
        
        
    }
    printf("Customer with ID %d is not found !!!\n",cid);   
}
void dispc(int x)
{
     
	FILE *fpc; 
	if(x==1)
	{
		fpc=fopen("Processing.txt","r");
		while(1)
		{
			chc=fgetc(fpc); 
			if(chc==EOF)
	    		break;
	    	printf("%c",chc);
		}
	}
	if(x==2)
	{
		fpc=fopen("Delivered.txt","r");
		while(1)
		{
			chc=fgetc(fpc);
			if(chc==EOF)
	    		break;
	    	printf("%c",chc);
		}
	}
}

void csearch()
{
	   time_t t;  
         time(&t);
    
	
	int cuid,choice;
	cfirst=NULL;
	char chc;
	FILE *fpc= fopen("Processing.txt", "r");
    	char buffer[1024];
        int column = 0;
        while (fgets(buffer,1024,fpc)!=NULL)
        {
        	column=0;
        	char* value = strtok(buffer," ");
        	struct customer *newn=(struct customer *)malloc(sizeof(struct customer));
        	while(value)
        	{
        		if(column==0)
			    {
               	    newn->idc=atoi(value);
                }
                if(column==1)
			    {
               	    strcpy(newn->cname,value);
                }
                if(column==2)
				{
                     newn->cmno=atoi(value);
                }
                if(column==3)
				{
               	    strcpy(newn->cmail,value);
                }
                if(column==4)
				{
                	strcpy(newn->type,value);
				}
                if(column==5)
				{
             	    newn->copies=atoi(value);
                }
           	    if(column==7)
				{
               	    strcpy(newn->status,value); 
           	    }
			    value = strtok(NULL," ");
	            column++;
	       }
	       if(column==2)
	       {
	       	   struct customer *temp=root;
    			if(root==NULL)
    			{
        			root=getNode(atoi(value));
        			//return(root);
    			}
    			while(1)
    			{
    			    if(temp->cmno>atoi(value))
      			    {
            			if(temp->lchild==NULL)
            			{
            			    temp->lchild=getNode(atoi(value));
             			   break;
            			}
            			else
            			{
            			    temp=temp->lchild;
           				}
        			}
        			else
        			{
         		 	  	if(temp->rchild==NULL)
          		  		{
            		    	temp->rchild=getNode(atoi(value));
            		    	break;
            			}
           				else
            			{
           				    temp=temp->rchild;
            			}
                
       				}
    			}
	       	
	   		}
	   		
}
/*int mobile;
printf("\nenter mobile number :");
scanf("%lli",&mobile);*/

}
void peek()


{
    int x;
    ctemp=cfirst;
    if(cfirst==NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
            FILE *fp;
            if(fp==NULL)
            {
            	printf("\nfile cant open");
              
			}
			else
			{
				ctemp=cfirst;
			  	FILE *fp=fopen("Processing.txt","a");
			  	while(ctemp!=NULL)
			  	{
			  		fprintf(fp,"\n%d %s %lli %s %s %d Rs.%d %s",ctemp->idc,ctemp->cname,ctemp->cmno,ctemp->cmail,ctemp->type,ctemp->copies,ctemp->copies*price,ctemp->status);
			  		ctemp=ctemp->clink;
				}
				fclose(fp);
			  
			}
			dequeue();

    }
}
int count()
{
    int c=0;
    ctemp=cfirst;
    while(ctemp!=NULL)
    {
        ctemp=ctemp->clink;
        c++;
    } 
    ctemp=NULL;
    return c;
}
void dequeue()
{
	printf("hi");
    if(cfirst==NULL)
    {
        printf("queue is empty now! \n");
    }
    else
    {
        
        while(cfirst!=NULL)
        {
        	ctemp=cfirst;
        	cfirst=cfirst->clink;
            free(ctemp);
        }
    }
}
int queuecheckid(int b)
{
	ctemp=cfirst;
	int m;
	while(ctemp!=NULL) 
	{
		
		if(ctemp->idc==b)
		{
			
			return 1;
		
		}
	ctemp=ctemp->clink;	
	}
}
struct customer* getNode(int value)
{
    struct customer *newn=(struct customer*)malloc(sizeof(struct customer));
    newn->cmno=value;
    newn->lchild=NULL;
    newn->rchild=NULL;
    return(newn);
}
/*void inorderpre(struct customer *root)
{
	
	if(root->cmno==mobile)
	{
	   printf("\nCustomer details found");
	   printf("\n%d \n%s \n%lli \n%s \n%s \n%d \nRs.%d \n%s",root->idc,root->cname,root->cmno,root->cmail,root->type,root->copies,root->copies*price,root->status);
	if(root->lchild!=NULL)
	{
        inorderpre(root->lchild);
    }
    if(i==0)
	{
    	 printf("The Inorder Predecessor of %d does not exist\n",root->data);
	}
	else
	{
    printf("The Inorder Predecessor of %d is %d\n",root->data,i);
	}
    i=root->data;
    if(root->rchild!=NULL)
	{
        inorderpre(root->rchild);
    
   }
    
}*/
