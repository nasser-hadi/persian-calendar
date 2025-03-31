 #include <stdio.h>
 #include <conio.h>
 #include <string.h>
 #include <iostream>

 using namespace std;

/*_____________________________    ____________________________*/

 void  Date3(char S_td[] ,int& ,int& ,int& ,int&); 

/*______________________________    _____________________________*/

 int  main(){

			    
 char  S_td[25];
 int   M;
 int   D;
 int   W;
 int   Sum=0;

 cout <<"\nEnter Date(Www/Mmm/dd/hh:mm:ss/yyyy):";
 
	  cin >> S_td;
	
	 Date3(S_td,Sum,M,D,W);
	 cout << S_td << endl;
	 for(int l=0;l<25;l++)
	 {
		cout << S_td[l];
	 }
	
 return 0;
 } //main ____________________________________________________________________

 void  Date3(char S_td[25] ,int& Sum ,int& M ,int& D ,int& W){

// char  S_td[25] :
// int&  Sum :
// int&  M :
// int&  D :
// int&  W :
			     
 unsigned int  ND[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 unsigned int  b=0;
 unsigned int  i;
 unsigned int  j;
 unsigned int  Y;
 char          N[11]={"0123456789"};
 char          NMS[12][9]={"Farvardn","Ordibehe"," Khordad","  Tir   "," Mordad ","Shahrivr","  Mehr  ","  Aban  ",
			   "  Azar  ","  Dey   "," Bahman "," Esfand"};
 char	       NMM[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
 char	       NWS[7][10]={" Shanbeh ","Yekshanbe","Doshanbeh","Seshanbeh","Charshanb","Panjshanb","  Jomeh  "};
 char          NWM[7][4]={"Sat","Sun","Mon","Tue","Wed","Thu","Fri"};
 char          S1[4];
 char          S2[4];
			      
 S1[0]=S_td[4];
 S1[1]=S_td[5];
 S1[2]=S_td[6];
 S1[3]='\0';
 
 S2[0]=S_td[0];
 S2[1]=S_td[1];
 S2[2]=S_td[2];
 S2[3]='\0';// Insert null character to truncate the string
 
 D=(S_td[8]-48)*10+(S_td[9]-48);
 Y=(S_td[20]-48)*1000+(S_td[21]-48)*100+(S_td[22]-48)*10+(S_td[23]-48);
 
 for(i=0; i<25; i++)
	  S_td[i]='\0';// Insert null character to truncate the string
 i=0;
 do
  M=i+1;
 while(strcmp(S1,NMM[i++]));
 for(i=0; i<M-1; i++)
	  Sum+=ND[i];
 if((Y%4)==0 && Sum>=59)  Sum+=D+1;
 else                     Sum+=D;
 Sum-=79;
 if((Y-1)%4==0 && Sum==0) b=1;
 if((Y-1)%4==0 && Sum<0)  Sum++;
 if(Sum<=0)               Y-=622;
 else                     Y-=621;
 for(i=0,j=1000; i<4; i++,j/=10){
		 S_td[i]=N[Y/j];
		 Y%=j;
				} //for i

 if(Sum<=0)      Sum+=365;
 if(b)           Sum++;
 if(Sum<=186){
	M=Sum/31;
	D=Sum%31;
	if(D==0){
	     strcat(S_td,NMS[M-1]);

	     S_td[12]='3';
	     S_td[13]='1';
             D=31;
		} //if D
	else{
	  strcat(S_td,NMS[M]);

	  S_td[12]=N[D/10];
	  S_td[13]=N[D%10];
          M++;
	    } //else
	     } //if Sum
 else{
   Sum-=186;
   M=Sum/30;
   D=Sum%30;
   if(D==0){
	strcat(S_td,NMS[M+5]);

	S_td[12]='3';
	S_td[13]='0';
        D=30;
	   } //if D
    else{
      strcat(S_td,NMS[M+6]);

      S_td[12]=N[D/10];
      S_td[13]=N[D%10];
      M++;
	} //else
 Sum+=186;
 M+=6;
     } //else
 i=0;
 do
  W=i+1;
 while(strcmp(S2,NWM[i++]));
 strcat(S_td,NWS[W-1]);
 } //Date3 ___________________________________________________________________

