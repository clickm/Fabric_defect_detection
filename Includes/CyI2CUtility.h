// *****************************************************************************
//
//     Copyright (c) 2002-2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyI2CUtility.h
//
// Description..: Utility class that wraps around CyDevice for convenient 
//                I2C communications.
//
// *****************************************************************************

#ifndef _CY_I2C_UTILITY_H_
#define _CY_I2C_UTILITY_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyDevice.h"
#include <CyAssert.h>


// class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyI2CUtility
{
#define I2C_START_CONDITION_MASK 0x1
#define I2C_STOP_CONDITION_MASK  0x2
#define I2C_FAST_MODE_MASK       0x4

public:
    CyI2CUtility( CyDevice& aDevice, unsigned long aPort )
        : mDevice( aDevice )
        , mPort( aPort )
    {
        CyAssert( aDevice.IsConnected () );
        CyAssert( aDevice.IsPortAvailable( mPort ) );

        aDevice.SetPortConfig(aPort,"N1-0,MODE:I2C");
    }
    
    virtual ~CyI2CUtility()
    {
    }

    CyDevice& GetDevice() const
    {
        return mDevice;
    }

    CyResult I2CMasterTransmitter (unsigned char        aSlaveAddress,
		                          const unsigned char* aBuffer,
		                          unsigned long        aBufferSize,
								  bool                 aFastMode = true,
								  bool                 aGenerateStopCondition = true)
    {
		unsigned long lBufferSize = aBufferSize + 1;
		unsigned char* lBuffer = new unsigned char[lBufferSize];
		
		lBuffer[0] = aSlaveAddress << 1;
		memcpy (&lBuffer[1], aBuffer, aBufferSize);

		unsigned long lInfo = I2C_START_CONDITION_MASK;

		if (aFastMode) {
			lInfo |= I2C_FAST_MODE_MASK;
		}

		if (aGenerateStopCondition) {
			lInfo |= I2C_STOP_CONDITION_MASK;
		}

#ifdef _CY_I2C_UTILITY_DEBUG_
		PrintBuffer (lBuffer, lBufferSize);
#endif

		CyResult lResult = mDevice.SendCommand (mPort, lBuffer, lBufferSize, lInfo);

		delete [] lBuffer;

		return lResult;
    }

    CyResult I2CMasterReceiverAfterFirstByte (unsigned char  aSlaveAddress,
		                                      unsigned char* aBuffer,
		                                      unsigned int*  aBufferSize,
											  bool           aFastMode = true,
								              bool           aGenerateStopCondition = true)
    {
		CyAssert (*aBufferSize < 65536);

		unsigned long lBufferSize = 3;
		unsigned char* lBuffer = new unsigned char[lBufferSize];

		lBuffer[0] = (aSlaveAddress << 1) | 0x1;
		lBuffer[1] = *aBufferSize & 0xFF;
		lBuffer[2] = (*aBufferSize & 0xFF00) >> 8;
		
		unsigned long lInfo = I2C_START_CONDITION_MASK;

		if (aFastMode) {
			lInfo |= I2C_FAST_MODE_MASK;
		}

		if (aGenerateStopCondition) {
			lInfo |= I2C_STOP_CONDITION_MASK;
		}

#ifdef _CY_I2C_UTILITY_DEBUG_
		PrintBuffer (lBuffer, lBufferSize);
#endif
		CyResult lResult = mDevice.ResetAnswerQueue (mPort);

		if (lResult != CY_RESULT_OK)
		{
#ifdef _CY_I2C_UTILITY_DEBUG_
			printf("I2CMasterReceiverAfterFirstByte (ResetAnswerQueue)- Error, lResult = %d\n", lResult);
#endif
			return lResult;
		}

		lResult = mDevice.SendCommand (mPort, lBuffer, lBufferSize, lInfo);

		if (lResult != CY_RESULT_OK)
		{
#ifdef _CY_I2C_UTILITY_DEBUG_
			printf("I2CMasterReceiverAfterFirstByte (SendCommand) - Error, lResult = %d\n", lResult);
			printf("I2CMasterReceiverAfterFirstByte (SendCommand) - lBufferSize = %d, lInfo = %x\n",		
				lBufferSize, lInfo);
			PrintBuffer (lBuffer, lBufferSize);
#endif
			return lResult;

		}

		delete [] lBuffer;

		// Number of bits to receive.

		lInfo = *aBufferSize * 9;

		// Devide by bit rate.

		if (aFastMode)
		{
			lInfo /= 400000;
		}
		else
		{
			lInfo /= 100000;
		}

		// Convert to ms.

		lInfo *= 1000;
		lInfo += 50;  // Add 50ms for when lInfo = 0

		lResult = mDevice.ReceiveAnswer (mPort, (unsigned char *) aBuffer, aBufferSize, lInfo);

		if (lResult != CY_RESULT_OK)
		{
#ifdef _CY_I2C_UTILITY_DEBUG_
			printf("I2CMasterReceiverAfterFirstByte (ReceiveAnswer) - Error, lResult = %d\n", lResult);
			printf("I2CMasterReceiverAfterFirstByte (ReceiveAnswer) - aBufferSize = %d, lInfo = %x\n", 
				*aBufferSize, lInfo);
			PrintBuffer (aBuffer, *aBufferSize);
#endif
		}
		
		return lResult;
    }

    CyResult I2CBurstWrite (unsigned char        aSlaveAddress,
		                    const unsigned char* aBuffer,
		                    unsigned long        aBufferSize,
							bool                 aFastMode = true)
    {
		return I2CMasterTransmitter (aSlaveAddress, aBuffer, aBufferSize, aFastMode);
    }

    CyResult I2CIndirectBurstWrite (unsigned char        aSlaveAddress,
		                            unsigned char        aOffset,
		                            const unsigned char* aBuffer,
		                            unsigned long        aBufferSize,
							        bool                 aFastMode = true)
    {
		unsigned long lBufferSize = aBufferSize + 1;
		unsigned char* lBuffer = new unsigned char[lBufferSize];

		lBuffer[0] = aOffset;
		memcpy (&lBuffer[1], aBuffer, aBufferSize);
		
		CyResult lResult = I2CMasterTransmitter (aSlaveAddress, lBuffer, lBufferSize, aFastMode);

		delete [] lBuffer;

		return lResult;
    }

    CyResult I2CIndirectSingleWrite (unsigned char aSlaveAddress,
		                             unsigned char aOffset,
		                             unsigned char aData,
							         bool          aFastMode = true)
    {
		unsigned char* lBuffer = new unsigned char[1];

		lBuffer[0] = aData;
		CyResult lResult = I2CIndirectBurstWrite (aSlaveAddress, aOffset, lBuffer, 1, aFastMode);

		delete [] lBuffer;

		return lResult;
    }

    CyResult I2CBurstRead (unsigned char  aSlaveAddress,
		                   unsigned char* aBuffer,
		                   unsigned int*  aBufferSize,
						   bool           aFastMode = true)
    {
		return I2CMasterReceiverAfterFirstByte (aSlaveAddress, aBuffer, aBufferSize, aFastMode);
    }

    CyResult I2CIndirectBurstRead (unsigned char  aSlaveAddress,
		                           unsigned char  aOffset,
		                           unsigned char* aBuffer,
		                           unsigned int*  aBufferSize,
						           bool           aFastMode = true,
							       bool           aUseCombinedFormat = true)
    {
		unsigned long lBufferSize = 1;
		unsigned char* lBuffer = new unsigned char[lBufferSize];
		bool lGenerateStopCondition;

		lBuffer[0] = aOffset;

		if (aUseCombinedFormat)
		{
			lGenerateStopCondition = false;
		}
		else
		{
			lGenerateStopCondition = true;
		}

		CyResult lResult = I2CMasterTransmitter (aSlaveAddress, lBuffer, lBufferSize, aFastMode, lGenerateStopCondition);

		if (lResult != CY_RESULT_OK)
		{
#ifdef _CY_I2C_UTILITY_DEBUG_
			printf("I2CIndirectBurstRead - aSlaveAddress = 0x%x, aOffset = 0x%X, lBufferSize = %d\n", 
					aSlaveAddress, aOffset, lBufferSize);
			printf("I2CIndirectBurstRead - Error, lResult = %d\n", lResult);
#endif
			return lResult;
		}

		lResult = I2CMasterReceiverAfterFirstByte (aSlaveAddress, aBuffer, aBufferSize, aFastMode);
		if (lResult != CY_RESULT_OK)
		{
#ifdef _CY_I2C_UTILITY_DEBUG_
			printf("I2CIndirectBurstRead -  aSlaveAddress = 0x%x, aBufferSize = %d\n", 
					aSlaveAddress, *aBufferSize);
			printf("I2CIndirectBurstRead - Error, lResult = %d\n", lResult);
#endif
		}
		return lResult;

    }

    CyResult I2CIndirectSingleRead (unsigned char  aSlaveAddress,
		                            unsigned char  aOffset,
		                            unsigned char* aData,
						            bool           aFastMode = true,
							        bool           aUseCombinedFormat = true)
    {
		unsigned int lBufferSize = 1;

		return I2CIndirectBurstRead (aSlaveAddress, aOffset, aData, &lBufferSize, aFastMode, aUseCombinedFormat);
	}

private:
    mutable CyDevice& mDevice;
    unsigned long     mPort;

	void PrintBuffer (const unsigned char* aBuffer,
		              unsigned long        aBufferSize)
    {
		printf("CyI2CUtility - ");
		for (unsigned long I = 0; I < aBufferSize; I++)
		{
			printf ("%d (0x%x) ", *aBuffer, *aBuffer);
			*aBuffer++;
		}
		printf ("\n");
    }
};
#endif // __cplusplus

#endif // _CY_I2C_UTILITY_H_
