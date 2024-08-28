#include<stdio.h>
#include<string.h>

struct student
{
    int id;
    char fname;
    char name[20];
    float cgpa;
};

int main()
{
    struct student s1={100,'V',"Ronaldo",3.99};
    printf("The id is %d\n",s1.id);
    printf("The first name is %c\n",s1.fname);
    printf("The name is %s\n",s1.name);
    printf("The CGPA is %f\n",s1.cgpa);

     struct student s4;
     s1.id=10;
     s1.fname='A';
    s4.name[20]= strcpy(s4.name,"asif");
     s1.cgpa=3,9;
     printf("The id is %d\n",s4.id);
    printf("The first name is %c\n",s4.fname);
    printf("The name is %s\n",s4.name);
    printf("The CGPA is %f\n",s4.cgpa);


    struct student s2;
    s2=s1;
    printf("The id is %d\n",s2.id);
    printf("The first name is %c\n",s2.fname);
    printf("The name is %s\n",s2.name);
    printf("The CGPA is %f\n",s2.cgpa);

  /*  struct student s3;
    scanf("%d",&s1.id);
    scanf("%c",&s1.fname);
    scanf("%s",&s1.name);
    scanf("%f",&s1.cgpa); */



    return 0;
}
