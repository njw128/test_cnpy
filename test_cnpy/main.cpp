#include <QCoreApplication>
#include"cnpy.h"
#include<complex>
#include<cstdlib>
#include<iostream>
#include<map>
#include<string>
#include<QtDebug>
#include<QDir>
#include<QDateTime>
using namespace std;



 size_t Nx = 3;
 size_t Ny = 4;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir tempDir;

    QString dayStr=QDateTime::currentDateTime().toString("yyyyMMdd");
    QString dirpath="../"+dayStr+"_data";
    if(!tempDir.exists(dirpath)){
        tempDir.mkpath(dirpath);
    }

    std::vector<double> data(Nx*Ny);
    for(int i = 0;i < Nx*Ny;i++)
        data[i] =rand();
    cnpy::npy_save("../arr1_new.npy",&data[0],{Ny,Nx},"w");


    double myVar1 = 1.2;
    char myVar2 = 'a';
    string fileName=dirpath.toStdString()+"/out.npz";
    cnpy::npz_save(fileName,"myVar1",&myVar1,{1},"w");
    cnpy::npz_save(fileName,"myVar2",&myVar2,{1},"a"); //"a" appends to the file we created above
//    cnpy::npz_save("../data/out.npz","arr1",&data[0],{Nz,Ny,Nx},"a");
    qInfo("over");


    return a.exec();
}
