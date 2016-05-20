#include <mex.h>
#include <vector>

int getCoordinate(int i, int j, int numRows) 
{
    return j*numRows + i;
}
    
void printImage(double *img, int numRows, int numCols)
{
    std::vector<double> testVector;
    for(int i=0; i<numRows; ++i) {
        for(int j=0; j<numCols; ++j) {
            mexPrintf("%lf\n", img[getCoordinate(i,j,numRows)]);
            testVector.push_back(img[getCoordinate(i,j,numRows)]);
        }   
    }
    
    int vecSize = testVector.size();    
    for(int i=1; i<=vecSize; ++i) {
        mexPrintf("%lf\n", testVector.back());
        testVector.pop_back();
    }  
    
}

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{   
    /* check proper input and output */
    if(nrhs!=1)
        mexErrMsgIdAndTxt( "MATLAB:phonebook:invalidNumInputs",
                "One input required.");
    else if(nlhs > 0)
        mexErrMsgIdAndTxt( "MATLAB:phonebook:maxlhs",
                "Too many output arguments.");
    else if(!mxIsDouble(prhs[0]))
        mexErrMsgTxt("Input must be double.");
    
    
    double *img;
    int numRows, numCols;
    
    img = mxGetPr(prhs[0]); // get the image
    numCols = mxGetN(prhs[0]);
    numRows = mxGetM(prhs[0]);
    
    printImage(img, numRows, numCols);
}

