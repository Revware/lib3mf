/*++

Copyright (C) 2015 netfabb GmbH (Original Author)

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Abstract:

NMR_ModelBuildItem.h defines the Model Build Item Class.
A model build item is an in memory representation of the 3MF
build item.

--*/

#ifndef __NMR_MODELBUILDITEM
#define __NMR_MODELBUILDITEM

#include "Model/Classes/NMR_Model.h" 
#include "Model/Classes/NMR_ModelObject.h" 
#include "Model/Classes/NMR_ModelMetaData.h" 
#include "Common/NMR_Types.h" 
#include "Common/Math/NMR_Matrix.h" 

namespace NMR {

	class CModelObject;
	
	typedef std::shared_ptr <CModelObject> PModelObject;

	class CModelBuildItem {
	private:
		CModelObject * m_pObject;
		NMATRIX3 m_mTransform;
		std::wstring m_sPartNumber;
		
	public:
		CModelBuildItem() = delete;
		CModelBuildItem(_In_ CModelObject * pObject);
		CModelBuildItem(_In_ CModelObject * pObject, _In_ const NMATRIX3 mTransform);
		~CModelBuildItem();
		
		CModelObject * getObject ();
		CModel * getModel();

		// Transform getter/setter
		NMATRIX3 getTransform ();
		void setTransform(_In_ const NMATRIX3 mTransform);
		nfBool hasTransform();
		std::wstring getTransformString();

		// Associated object getter/setter
		ModelResourceID getObjectID();

		// Item reference getter/setter
		std::wstring getPartNumber();
		void setPartNumber(_In_ std::wstring sPartNumber);

		// Merge the build item to the given mesh
		void mergeToMesh(_In_ CMesh * pMesh);

	};

	typedef std::shared_ptr <CModelBuildItem> PModelBuildItem;

}

#endif // __NMR_MODELBUILDITEM
