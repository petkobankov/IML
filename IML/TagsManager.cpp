#include "TagsManager.h"
#include "MyException.h"
int TagsManager::identifyTag(const Tag& input) const
{
	int tag_count = tag_masks.size();

	for (size_t tag_mask = 0; tag_mask < tag_count; tag_mask++)
	{
		if (tag_masks[tag_mask].hasSameName(input.getName()))
			return tag_mask;
	}

	return -1;
}

bool TagsManager::doesTagExist(Tag& input)
{
	int id = identifyTag(input);
	input.setId(id);
	return (id != -1);
}

bool TagsManager::doesTagExist(const Tag& input) const
{
	int id = identifyTag(input);
	return (id != -1);
}

void TagsManager::executeTag(const Tag& input, std::vector<float>& numbers)
{

}

bool TagsManager::isAdditionalInfoCorrect(const std::string& info, int id)
{
	char mask_additional_info_type = tag_masks[id].getAdditionalInfoType();
	if (mask_additional_info_type == '\0') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not expect additional info.");
	}
	else if (mask_additional_info_type == 'N') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not accept additional info type number.");
	}

	return tag_masks[id].isAdditionalInfoAccepted(info);
}

bool TagsManager::isAdditionalInfoCorrect(float info, int id)
{
	char mask_additional_info_type = tag_masks[id].getAdditionalInfoType();
	if (mask_additional_info_type == '\0') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not expect additional info.");
		return false;
	}
	else if (mask_additional_info_type == 'S') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not accept additional info type string.");
		return false;
	}
	return true;
}
