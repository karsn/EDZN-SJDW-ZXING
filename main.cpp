/*******************************************************************************
Copyright(R) 2014-2024, MPR Tech. Co., Ltd
File Name: main.cpp
Author: Karsn           Date: 2018-03-09             Version: 1.0
Discription:

Function:

History:
1. Version: 1.0        Date: 2018-03-09         Author: Karsn
    Modification:
      Creation.
*******************************************************************************/

#include "ImageReaderSource.h"
#include <zxing/detector/Detector.h>
#include <zxing/common/HybridBinarizer.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/DecodeHints.h>

#include <time.h>

using namespace std;
using namespace zxing;
//using namespace zxing::multi;
using namespace zxing::qrcode;
	
/****************************** Private typedef *******************************/
/****************************** Private define ********************************/
/****************************** Private macro *********************************/
/***************************** Private variables ******************************/
/************************ Private function prototypes *************************/

/*******************************************************************************
Function: 
Description:
Calls:
Called By:
Table Accessed:
Table Updated:
Input:
Output:
Return:
Others:
*******************************************************************************/
int main(int argc, char** argv)
{
	string filename = argv[1];
	Ref<LuminanceSource> source;
	
	clock_t TStart = clock();
	
    try {
      source = ImageReaderSource::create(filename);
    } catch (const zxing::IllegalArgumentException &e) {
      cerr << e.what() << " (ignoring)" << endl;
      //continue;
    }
    
    Ref<Binarizer> binarizer;
    binarizer = new HybridBinarizer(source); //implements a local thresholding algorithm
    Ref<BinaryBitmap> binary(new BinaryBitmap(binarizer));
    
    DecodeHints hints(DecodeHints::DEFAULT_HINT);
    hints.setTryHarder(true);
    
	Detector detector(binary->getBlackMatrix());
	Ref<DetectorResult> detectorResult(detector.detect(hints));
	ArrayRef< Ref<ResultPoint> > points (detectorResult->getPoints());
	
	clock_t TDelt = clock() - TStart;
	cout << "Spend Time =" << (double)TDelt/CLOCKS_PER_SEC<<"s"<<endl;
	
	for (int j = 0; j < points->size(); j++) 
	{
      cout << "  Point[" << j <<  "]: "
           << points[j]->getX() << " "
           << points[j]->getY() << endl;
    }
	
}