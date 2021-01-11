#include "TagMask.h"

bool TagMask::isAdditionalInfoAccepted(const std::string& info)const
{
	if (!hasAdditionalInfoBoundry())
		return true;
    int boundrySize = additional_info_boundry.size();
	for (size_t i = 0; i < boundrySize; i++)
	{
		if (additional_info_boundry[i] == info)
			return true;
	}
	return false;
}
