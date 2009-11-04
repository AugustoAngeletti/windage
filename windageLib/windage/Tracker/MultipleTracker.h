/* ========================================================================
 * PROJECT: windage Library
 * ========================================================================
 * This work is based on the original windage Library developed by
 *   Woonhyuk Baek
 *   Woontack Woo
 *   U-VR Lab, GIST of Gwangju in Korea.
 *   http://windage.googlecode.com/
 *   http://uvr.gist.ac.kr/
 *
 * Copyright of the derived and new portions of this work
 *     (C) 2009 GIST U-VR Lab.
 *
 * This framework is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this framework; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * For further information please contact 
 *   Woonhyuk Baek
 *   <windage@live.com>
 *   GIST U-VR Lab.
 *   Department of Information and Communication
 *   Gwangju Institute of Science and Technology
 *   1, Oryong-dong, Buk-gu, Gwangju
 *   South Korea
 * ========================================================================
 ** @author   Woonhyuk Baek
 * ======================================================================== */

#ifndef _MULTIPLE_TRACKER_H_
#define _MULTIPLE_TRACKER_H_

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#include <vector>
#include <cv.h>
#include <cvaux.h>

#include "Tracker.h"
#include "OpticalFlow.h"
#include "Utils/Logger.h"

namespace windage
{
	class DLLEXPORT MultipleTracker : public Tracker
	{
	protected:
		std::vector<IplImage*> referenceImageList;
		std::vector<Calibration*> cameraParameterList;

		OpticalFlow* opticalflow;

		virtual void Release();

	public:
		MultipleTracker()
		{
			opticalflow = NULL;
		}
		~MultipleTracker()
		{
			this->Release();
		}

//		void AttatchReferenceImage(IplImage* image) = 0;
		virtual bool DeleteReferenceImage(int index) = 0;
		Calibration* GetCameraParameter(int index = -1);
		
		void InitializeOpticalFlow(
									int width,							///< input image width size
									int height,							///< input image height size
									CvSize windowSize=cvSize(10, 10),	///< opticalflow window size
									int pyramidLevel=3					///< opticalflow pyramid level
									);

	};
}

#endif