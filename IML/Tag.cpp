#include "Tag.h"

void Tag::setAdditionalInfoStr(const std::string& _additional_info_s)
{
	additional_info_s = _additional_info_s;
	has_additional = true;
}

void Tag::setAdditionalInfoFloat(float _additional_info_f)
{
	additional_info_f = _additional_info_f;
	has_additional = true;
}
