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

#include <zxing/detector/Detector.h>

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
	Detector detector(image->getBlackMatrix());
	Ref<DetectorResult> detectorResult(detector.detect(hints));
	ArrayRef< Ref<ResultPoint> > points (detectorResult->getPoints());
	
}