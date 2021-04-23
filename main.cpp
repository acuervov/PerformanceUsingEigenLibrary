#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Eigenvalues>
#include <chrono>
#include <fstream>

typedef Eigen::Matrix <double, Eigen::Dynamic,Eigen::Dynamic> Matriz;

void Matrixmaker ();
void Matrixsolver (Matriz x,double & time);


int main ()
{
  
  Matrixmaker();

  return 0;
  
}

void Matrixmaker()
{

  std::ofstream print ("resultados.txt");
  
  int N=4;
  double time=0;
  
  for (int ii=0;ii<5;ii++){
    
  Matriz a=Eigen::MatrixXd::Random (N,N);
  //std::cout << a.rows()<<std::endl;
  //std::cout << " " << std::endl;
  Matrixsolver (a,time);

  print<<N<<" "<<time/0.000327776<<std::endl;
  N=2*N;
  }
  print.close ();
}

void Matrixsolver (Matriz a,double & time)
{

 
  auto start = std::chrono::steady_clock::now();
  Eigen::VectorXcd av=a.eigenvalues();
 
  Eigen::EigenSolver<Matriz> aV (a);

  auto end = std::chrono::steady_clock::now();

  std::chrono ::duration<double> elapsed_seconds= end-start;
  
  
  
  //print << size<< " "<< elapsed_seconds.count()<<std::endl;
  time =elapsed_seconds.count();
  
  std::cout<<aV.eigenvectors().col(0)<<"n/ "<<av<<std::endl;
  std::cout <<" "<<std::endl;

  
}

