#ifndef _MFnUnitAttribute
#define _MFnUnitAttribute
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related
// material (collectively the "Data") in these files contain unpublished
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its
// licensors,  which is protected by U.S. and Canadian federal copyright law
// and by international treaties.
//
// The Data may not be disclosed or distributed to third parties or be
// copied or duplicated, in whole or in part, without the prior written
// consent of Autodesk.
//
// The copyright notices in the Software and this entire statement,
// including the above license grant, this restriction and the following
// disclaimer, must be included in all copies of the Software, in whole
// or in part, and all derivative works of the Software, unless such copies
// or derivative works are solely in the form of machine-executable object
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE,
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES.
// ==========================================================================
//+
//
// CLASS:    MFnUnitAttribute
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnAttribute.h>

// ****************************************************************************
// DECLARATIONS

class MString;
class MTime;
class MAngle;
class MDistance;

// ****************************************************************************
// CLASS DECLARATION (MFnUnitAttribute)

//! \ingroup OpenMaya MFn
//! \brief Unit attribute Function set. 
/*!
  MFnUnitAttribute is the function set for dependency nodes attributes
  that store one of the fundamental types of Maya data.  The currently
  supported types are MAngle, MDistance, and MTime.

  It is possible to set the defaults using a double.  This is valid
  for angles and distances.  In the case of angles, the value is
  assumed to be in radians, and in the case of distances, it is
  assumed to be in centimeters.  Time values should not be set using a
  double.

  It is possible to use unit attributes in place of double attributes
  when creating numeric compounds (see MFnNumericAttrbute).  To create
  a numeric compound of three distance values, create the three child
  attributes using MFnUnitAttribute and then pass the children into
  the create method of MFnNumericAttribute.
*/
class OPENMAYA_EXPORT MFnUnitAttribute : public MFnAttribute
{
	declareMFn(MFnUnitAttribute, MFnAttribute);

public:

	//! Type of unit represented by attribute values 
	enum Type {
		kInvalid,	//!< Invalid unit type
		kAngle,     //!< Angular attribute
		kDistance,  //!< Distance (linear) attribute
		kTime,		//!< Time attribute
		kLast		//!< Last value, for counting
	};

	MObject 	create( const MString& fullName,
						const MString& briefName,
						MFnUnitAttribute::Type unitType,
						double defaultValue = 0.0,
						MStatus* ReturnStatus = NULL );
	MObject 	create( const MString& fullName,
						const MString& briefName,
						const MTime& defaultValue,
						MStatus* ReturnStatus = NULL );
	MObject 	create( const MString& fullName,
						const MString& briefName,
						const MAngle& defaultValue,
						MStatus* ReturnStatus = NULL );
	MObject 	create( const MString& fullName,
						const MString& briefName,
						const MDistance& defaultValue,
						MStatus* ReturnStatus = NULL );
	MFnUnitAttribute::Type	unitType( MStatus* ReturnStatus = NULL ) const;
	bool		hasMin( MStatus* ReturnStatus = NULL) const;
	bool		hasMax( MStatus* ReturnStatus = NULL) const;
	bool		hasSoftMin( MStatus* ReturnStatus = NULL) const;
	bool		hasSoftMax( MStatus* ReturnStatus = NULL) const;
	MStatus		getMin( double& minValue ) const;
	MStatus		getMin( MTime& minValue ) const;
	MStatus		getMin( MAngle& minValue ) const;
	MStatus		getMin( MDistance& minValue ) const;
	MStatus		getMax( double& maxValue ) const;
	MStatus		getMax( MTime& maxValue ) const;
	MStatus		getMax( MAngle& maxValue ) const;
	MStatus		getMax( MDistance& maxValue ) const;
	MStatus		getSoftMin( double& minValue ) const;
	MStatus		getSoftMin( MTime& minValue ) const;
	MStatus		getSoftMin( MAngle& minValue ) const;
	MStatus		getSoftMin( MDistance& minValue ) const;
	MStatus		getSoftMax( double& maxValue ) const;
	MStatus		getSoftMax( MTime& maxValue ) const;
	MStatus		getSoftMax( MAngle& maxValue ) const;
	MStatus		getSoftMax( MDistance& maxValue ) const;
	MStatus		setMin( double minValue );
	MStatus		setMin( const MTime &minValue );
	MStatus		setMin( const MAngle &minValue );
	MStatus		setMin( const MDistance &minValue );
	MStatus		setMax( double maxValue );
	MStatus		setMax( const MTime &maxValue );
	MStatus		setMax( const MAngle &maxValue );
	MStatus		setMax( const MDistance &maxValue );
	MStatus		setSoftMin( double minValue );
	MStatus		setSoftMin( const MTime &minValue );
	MStatus		setSoftMin( const MAngle &minValue );
	MStatus		setSoftMin( const MDistance &minValue );
	MStatus		setSoftMax( double maxValue );
	MStatus		setSoftMax( const MTime &maxValue );
	MStatus		setSoftMax( const MAngle &maxValue );
	MStatus		setSoftMax( const MDistance &maxValue );
	MStatus		getDefault( double & defaultValue );
	MStatus		getDefault( MTime & defaultValue );
	MStatus     getDefault( MAngle & defaultValue );
	MStatus     getDefault( MDistance & defaultValue );
	MStatus		setDefault( double defaultValue );
	MStatus		setDefault( const MTime& defaultValue );
	MStatus     setDefault( const MAngle& defaultValue );
	MStatus     setDefault( const MDistance& defaultValue );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnUnitAttribute, MFnAttribute );

END_NO_SCRIPT_SUPPORT:

};

#endif /* __cplusplus */
#endif /* _MFnUnitAttribute */