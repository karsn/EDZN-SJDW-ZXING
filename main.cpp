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

using zxing::qrcode;
	
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
	Ref<LuminanceSource> source;
    try {
      source = ImageReaderSource::create(filename);
    } catch (const zxing::IllegalArgumentException &e) {
      cerr << e.what() << " (ignoring)" << endl;
      //continue;
    }
    
    Ref<Binarizer> binarizer;
    binarizer = new HybridBinarizer(source);
    Ref<BinaryBitmap> binary(new BinaryBitmap(binarizer));
    
    DecodeHints hints(DecodeHints::DEFAULT_HINT);
    hints.setTryHarder(try_harder);
    
	Detector detector(image->getBlackMatrix());
	Ref<DetectorResult> detectorResult(detector.detect(hints));
	ArrayRef< Ref<ResultPoint> > points (detectorResult->getPoints());
	
}