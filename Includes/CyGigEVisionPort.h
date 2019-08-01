// *****************************************************************************
//
//     Copyright (c) 2006, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGigEVisionPort.h
//
// Description..: 
//
// *****************************************************************************

#ifndef __CY_GIGE_VISION_PORT_H__
#define __CY_GIGE_VISION_PORT_H__

#ifdef CY_IMPLEMENT_GENICAM

#include <GenApi/GenApi.h>
#include <GenApi/PortImpl.h>

#include <CyGigEVisionDevice.h>

class CyGigEVisionPortImpl;


class CyGigEVisionPort : public GenApi::IPort
{
public:

	CyGigEVisionPort( CyDevice *aDevice );
	virtual ~CyGigEVisionPort();

	// IBase implementation
	virtual GenApi::EAccessMode GetAccessMode() const;

    // IPort implementation
	virtual void Read( void *aBuffer, int64_t aAddress, int64_t aLength );
	virtual void Write( const void *aBuffer, int64_t aAddress, int64_t aLength );

    // Ignore ACK or not, reset after Read/Write
    void SetIgnoreACK( bool aIgnored );

protected:

private:

	 // Not implemented
	CyGigEVisionPort( const CyGigEVisionPort & );
	const CyGigEVisionPort &operator=( const CyGigEVisionPort & );

	// Hidden implementation
	CyGigEVisionPortImpl *mThis;
};

#endif // CY_IMPLEMENT_GENICAM

#endif // __CY_GIGE_VISION_PORT_H__
