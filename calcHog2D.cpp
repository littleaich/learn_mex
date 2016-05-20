#include "mex.h"
#include "matrix.h"

const char cellSize_name[] = "cellSize";
const char blockSize_name[] = "blockSize";
const char numBins_name[] = "numBins";
const char blockOverlap_name[] = "blockOverlap";
const char orientationSigned_name[] = "orientationSigned";

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{   
    /* check proper input and output */
    if(nrhs!=4)
        mexErrMsgIdAndTxt( "MATLAB:phonebook:invalidNumInputs",
                "Three inputs required.");
    else if(nlhs > 1)
        mexErrMsgIdAndTxt( "MATLAB:phonebook:maxlhs",
                "Too many output arguments.");
    else if(!mxIsSingle(prhs[0]) || !mxIsSingle(prhs[1]) || 
            !mxIsSingle(prhs[2]))
        mexErrMsgTxt("All inputs must be of Single type."); 
    
    mxArray *tmpStruct;
    double *img, *grad_x, *grad_y;
    int numRows, numCols;
    struct hogParams_ hogParams;
    
    // get the inputs
    img = mxGetPr(prhs[0]); // get the image
    grad_x = mxGetPr(prhs[1]); // get the horizontal gradient
    grad_y = mxGetPr(prhs[2]); // get the vertical gradient
    numCols = mxGetN(prhs[0]); // number of image columns
    numRows = mxGetM(prhs[0]); // number of image rows
    
    // get cellSize
    tmpStruct = mxGetField(prhs[3], 0, cellSize_name);
    hogParams.cellSize = static_cast<int>(mxGetScalar(tmpStruct));
    // get blockSize
    tmpStruct = mxGetField(prhs[3], 0, blockSize_name);
    hogParams.blockSize = static_cast<int>(mxGetScalar(tmpStruct));
    //get number of bins == numBins
    tmpStruct = mxGetField(prhs[3], 0, numBins_name);
    hogParams.numBins = static_cast<int>(mxGetScalar(tmpStruct));
    // get blockOverlap
    tmpStruct = mxGetField(prhs[3], 0, blockOverlap_name);
    hogParams.blockOverlap = static_cast<int>(mxGetScalar(tmpStruct));
    // get orientationSigned
    tmpStruct = mxGetField(prhs[3], 0, orientationSigned_name);
    hogParams.orientationSigned = static_cast<bool>(mxGetScalar(tmpStruct));
    
    /*
    // check input hog parameters
    mexPrintf("%i\n", hogParams.cellSize);
    mexPrintf("%i\n", hogParams.blockSize);
    mexPrintf("%i\n", hogParams.numBins);
    mexPrintf("%i\n", hogParams.blockOverlap);
    mexPrintf("%i\n", hogParams.orientationSigned);    
    */
    
    
    
}

