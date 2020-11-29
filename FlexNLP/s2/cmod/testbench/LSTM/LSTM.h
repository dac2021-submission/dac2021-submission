/*
 * Copyright (c) 2016-2018, Harvard University.  All rights reserved.
*/
#ifndef LSTM_H
#define LSTM_H

template < typename T >
std::vector< std::vector<T> > to_2d(const unsigned long nrows, const unsigned long ncols, const std::vector<T>& flat_vec)
{
    // sanity check
    if( ncols == 0 || flat_vec.size()%ncols != 0 ) throw std::domain_error( "bad #cols" ) ;
    


    std::vector< std::vector<T> > mtx ;
    const auto begin = std::begin(flat_vec) ;
    for( std::size_t row = 0 ; row < nrows ; ++row ) mtx.push_back( { begin + row*ncols, begin + (row+1)*ncols } ) ;
    return mtx ;
}

template<typename Scalar> 
void PrintVector(const std::vector<Scalar>& data)
{
  for (unsigned int i = 0; i < data.size(); i++)
    std::cout << data[i] << "\t"; 
  std::cout << std::endl;
}


template<typename Scalar> 
void PrintMatrix(const std::vector<std::vector<Scalar>>& data)
{
  for (unsigned int i = 0; i < data.size(); i++)
    PrintVector(data[i]);
  std::cout << std::endl;
}

template<typename Scalar> 
std::vector<std::vector<Scalar>> TransposeMatrix(const std::vector<std::vector<Scalar>>& data)
{
  std::vector<std::vector<Scalar>> out;
  
  
  for (unsigned j = 0; j < data[0].size(); j++) {
    std::vector<Scalar> out_row;
    for (unsigned i = 0; i < data.size(); i++) {
      out_row.push_back(data[i][j]);
    }
    out.push_back(out_row);
  }
  return out;
}

template<typename Scalar> 
void PrintMatrixShape(const std::vector<std::vector<Scalar>>& data) {
  std::cout << "[" << data.size() << ", " << data[0].size() << "]" << std::endl;
  const unsigned int ncols = data[0].size();
  for (unsigned int i = 0; i < data.size(); i++) {
    if( ncols != data[i].size()) throw std::domain_error( "bad #cols" ) ;  
  
  }
}

template<typename Scalar> 
std::vector<Scalar> VectorPadding(const std::vector<Scalar>& data, const int usize)
{
  std::vector<Scalar> out = data;
  unsigned size_new = usize * (1 + (data.size()-1)/usize);
  out.resize(size_new, 0.0);
  return out;
}

template<typename Scalar> 
std::vector<std::vector<Scalar>> MatrixPadding(const std::vector<std::vector<Scalar>>& data, const int usize)
{
  std::vector<std::vector<Scalar>> out;
  unsigned size_new = usize * (1 + (data.size()-1)/usize);
  out.resize(size_new); 
  

  // for each row 
  unsigned int i;
  for (i = 0; i < data.size(); i++) {
    out[i] = VectorPadding(data[i], usize);
  }
    
  for (     ; i < out.size(); i++) {
    std::vector<Scalar> tmp;
    tmp.resize(out[0].size(), 0.0);
    out[i] = tmp;
  }    
  
  return out;
}

template<typename Scalar> 
std::vector<Scalar> MatrixVectorMul(const std::vector<std::vector<Scalar>>& M, const std::vector<Scalar>& v) {
  std::vector<Scalar> out;
  out.resize(M.size(), 0.0);
  
  for (unsigned int i = 0; i < M.size(); i++) {
    for (unsigned int j = 0; j < v.size(); j++) {
      if( M[i].size() != v.size()) throw std::domain_error( "bad M[i].size() != v.size()" );          
      out[i] += M[i][j] * v[j];
    }
  } 
  
  return out;
}

template<typename Scalar> 
std::vector<Scalar> MatrixVectorMul(const std::vector<std::vector<Scalar>>& M, const std::vector<Scalar>& v, const std::vector<Scalar>& b) {
  std::vector<Scalar> out;
  out.resize(M.size(), 0.0);

  if( M.size() != b.size()) throw std::domain_error( "bad M.size() != b.size()" );          
  for (unsigned int i = 0; i < M.size(); i++) {
    for (unsigned int j = 0; j < v.size(); j++) {
      if( M[i].size() != v.size()) throw std::domain_error( "bad M[i].size() != v.size()" );          
      out[i] += M[i][j] * v[j];
    }
    out[i] += b[i];
  } 
  
  return out;
}


template<typename Scalar> 
std::vector<Scalar> VectorAdd(const std::vector<Scalar>& v1, const std::vector<Scalar>& v2){
  if( v1.size() != v2.size()) throw std::domain_error( "bad add v1.size() != v2.size()" );            
  std::vector<Scalar> out;
  out.resize(v1.size(), 0.0);
  for (unsigned int i = 0; i < v1.size(); i++) {
    out[i] = v1[i] + v2[i];
  }
  
  return out;
}

template<typename Scalar> 
std::vector<Scalar> VectorMul(const std::vector<Scalar>& v1, const std::vector<Scalar>& v2){
  if( v1.size() != v2.size()) throw std::domain_error( "bad mul v1.size() != v2.size()" );            
  std::vector<Scalar> out;
  out.resize(v1.size(), 0.0);
  for (unsigned int i = 0; i < v1.size(); i++) {
    out[i] = v1[i] * v2[i];
  }
  
  return out;
}

template<typename Scalar> 
std::vector<Scalar> VectorTanh(const std::vector<Scalar>& v){
  std::vector<Scalar> out;
  out.resize(v.size(), 0.0);
  for (unsigned int i = 0; i < v.size(); i++) {
    out[i] = tanh(v[i]);
  }
  
  return out;
}

template<typename Scalar> 
std::vector<Scalar> VectorSigmoid(const std::vector<Scalar>& v){
  std::vector<Scalar> out;
  out.resize(v.size(), 0.0);
  for (unsigned int i = 0; i < v.size(); i++) {
    out[i] = 1 / (1 + exp(-v[i]));
  }
  
  return out;
}

// mean absolute error
template<typename Scalar> 
Scalar VectorMAE(const std::vector<Scalar>& v1, const std::vector<Scalar>& v2){
  if( v1.size() != v2.size()) throw std::domain_error( "bad mul v1.size() != v2.size()" );            
  Scalar err;
  
  for (unsigned int i = 0; i < v1.size(); i++) {
    err = abs(v1[i] - v2[i]);
  }
  err = err / v1.size();
  
  return err;
}

double ReducePrecision(const double in){
  double out;
  float out_ft;
  out_ft = (float) in;
  
  unsigned int x = *reinterpret_cast<unsigned int*>(&out_ft);
  x = x & 0xfff80000;
  out_ft = *reinterpret_cast<float *>(&x);
  out = (double) out_ft;
  
  return out;
}

#endif 

