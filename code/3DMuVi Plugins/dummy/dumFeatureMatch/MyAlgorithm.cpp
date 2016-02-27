#include "algorithm.h"
#include "workflow/workflow/datapackets/CDataFeature.h"

//----------------------------------------
// Adjust these functions to your needs
//----------------------------------------

void _CLASS_GEN(Algorithm)::OnInitialize(){
    mInputTypes.push_back(DT_FEATURE_MATCH);
    mInputTypes.push_back(DT_INPUTIMAGES);
}

bool _CLASS_GEN(Algorithm)::ValidateParameters(const QJsonObject *params) const{
    return true;
}

void _CLASS_GEN(Algorithm)::executeAlgorithm(CContextDataStore *store){
    Q_UNUSED(store);
}
