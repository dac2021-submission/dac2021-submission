/*
 * Copyright (c) 2016-2018, Harvard University.  All rights reserved.
*/
#include <vector>
#include <iostream>
#include <string>
#include <math.h> // testbench only
#include <iomanip>
#include "../libnpy/npy.hpp"
#include "LSTM.h"

using namespace std;

class LSTM {
  const int usize = 16;
 
 public:  
  std::vector<std::vector<double>> Wx[4];
  std::vector<std::vector<double>> Wh[4];  
  std::vector<double>  bx[4];
  std::vector<double>  bh[4];
  
  std::vector<double>  h_t;
  std::vector<double>  c_t;
  
  LSTM() {}
  LSTM(const std::vector<std::vector<double>>& Wx_in, 
       const std::vector<std::vector<double>>& Wh_in,
       const std::vector<double>& bx_in,
       const std::vector<double>& bh_in) {
    // no proper checking 
    unsigned int nrows = Wx_in.size();
    
    for (unsigned int i = 0; i < nrows; i++) {
      unsigned int j = (i*4) / nrows;
      Wx[j].push_back(Wx_in[i]);
      Wh[j].push_back(Wh_in[i]);
      bx[j].push_back(bx_in[i]);
      bh[j].push_back(bh_in[i]);
    }
    for (unsigned int i = 0; i < 4; i++) {
      Wx[i] = MatrixPadding(Wx[i], usize);
      Wh[i] = MatrixPadding(Wh[i], usize);
      bx[i] = VectorPadding(bx[i], usize);
      bh[i] = VectorPadding(bh[i], usize);        
    }
    
    nrows = usize * (1 + (nrows -1)/usize);
    
    h_t.resize(Wx[0].size(), 0.0);
    c_t.resize(Wx[0].size(), 0.0);
  }

  
  std::vector<double> run(std::vector<double> x_t) {
  
    x_t = VectorPadding(x_t, usize);

    std::vector<double> tmp_x[4];
    std::vector<double> tmp_h[4];
    std::vector<double> tmp[4];  
    
    //PrintMatrixShape(Wx[0]);
    //PrintMatrixShape(Wh[0]);
    //std::std::cout << "x_t size " << x_t.size() << std::endl;
    //std::std::cout << "h_t size " << h_t.size() << std::endl;
    
    for (int i = 0; i < 4; i++){
      tmp_x[i] = MatrixVectorMul(Wx[i], x_t, bx[i]);
      tmp_h[i] = MatrixVectorMul(Wh[i], h_t, bh[i]);
      tmp[i]   = VectorAdd(tmp_x[i], tmp_h[i]);
      tmp_x[i].clear(); 
      tmp_h[i].clear();
    }
    
    tmp[0] = VectorSigmoid (tmp[0]); // i
    tmp[1] = VectorSigmoid (tmp[1]); // f
    tmp[2] = VectorTanh    (tmp[2]); // g
    tmp[3] = VectorSigmoid (tmp[3]); // o
    
    // c' = f*c + i*g
    std::vector<double> tmp_out[2];
    tmp_out[0]  = VectorMul(tmp[1], c_t);
    tmp_out[1]  = VectorMul(tmp[0], tmp[2]);    
    c_t         = VectorAdd(tmp_out[0], tmp_out[1]);
    // otanh(c')
    tmp_out[0]  = VectorTanh(c_t);
    h_t         = VectorMul(c_t, tmp[3]);
    
    for (unsigned int i = 0; i < c_t.size(); i++) {
      c_t[i] = ReducePrecision(c_t[i]);
      h_t[i] = ReducePrecision(h_t[i]);
    }
    
    
    return h_t;
  }
  
  
};


int main(){
  std::string filename;
  std::vector<unsigned long> npy_shape;
  std::vector<double>  npy_data;
  std::vector<std::vector<double>>  x_ref, h_ref;
  
  std::vector<double>  bx_ref, bh_ref;
  std::vector<std::vector<double>> Wx_ref, Wh_ref;

  npy_shape.clear(); npy_data.clear();
  npy::LoadArrayFromNumpy("../dataset/x_l0.npy", npy_shape, npy_data);

  x_ref = to_2d(npy_shape[0], npy_shape[2], npy_data);
  std::cout << npy_shape[0] << " " << npy_shape[1] << " " << npy_shape[2] << std::endl;
  
  
  
  npy_shape.clear(); npy_data.clear();
  npy::LoadArrayFromNumpy("../dataset/h_l0.npy", npy_shape, npy_data);
  h_ref = to_2d(npy_shape[0], npy_shape[2], npy_data);
  std::cout << npy_shape[0] << " " << npy_shape[1] << " " << npy_shape[2] << std::endl;
  
  npy_shape.clear(); npy_data.clear();
  npy::LoadArrayFromNumpy("../dataset/encoder.rnn_0.weight_ih_l0.npy", npy_shape, npy_data);
  Wx_ref = to_2d(npy_shape[0], npy_shape[1], npy_data);
  std::cout << npy_shape[0] << " " << npy_shape[1] << std::endl;  
  
  npy_shape.clear(); npy_data.clear();
  npy::LoadArrayFromNumpy("../dataset/encoder.rnn_0.weight_hh_l0.npy", npy_shape, npy_data);
  Wh_ref = to_2d(npy_shape[0], npy_shape[1], npy_data);
  std::cout << npy_shape[0] << " " << npy_shape[1] << std::endl;
  
  npy_shape.clear(); npy_data.clear();
  npy::LoadArrayFromNumpy("../dataset/encoder.rnn_0.bias_ih_l0.npy", npy_shape, npy_data);
  bx_ref = npy_data;
  std::cout << npy_shape[0] << std::endl;  
  
  npy_shape.clear(); npy_data.clear();
  npy::LoadArrayFromNumpy("../dataset/encoder.rnn_0.bias_hh_l0.npy", npy_shape, npy_data);
  bh_ref = npy_data;
  std::cout << npy_shape[0] << std::endl;
  
  LSTM lstm_cell(Wx_ref, Wh_ref, bx_ref, bh_ref);
  
  std::vector<std::vector<double>> h_out;
  h_out.resize(h_ref.size());
  
  
  for (unsigned int i = 0; i < h_ref.size(); i++) {
    h_out[i] = lstm_cell.run(x_ref[i]);
    std::cout << fixed << "time[" << i << "]: " <<  VectorMAE(h_ref[i], h_out[i]) << std::endl;
  }
  //double test;
  //cin >> test;
  //test = ReducePrecision(test);
  //std::cout << " => " << test << std::endl;
  

  
  //PrintVector(h_out);
  
  return 0;
}
