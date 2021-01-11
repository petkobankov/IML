#pragma once
#include "Tag.h"
#include "TagMask.h"
#include <vector>
class TagsManager {
	const std::vector<TagMask> tag_map = 
	{
		TagMask("MAP-INC",'N'),
		TagMask("MAP-MLT",'N')
	
	};
	const std::vector<TagMask> tag_aggregate =
	{
		TagMask("AGG-SUM"),
		TagMask("AGG-PRO"),
		TagMask("AGG-PRO"),
		TagMask("AGG-AVG"),
		TagMask("AGG-FST"),
		TagMask("AGG-LST")

	};
	const std::vector<TagMask> tag_sorting =
	{
		TagMask("SRT-REV"),
		TagMask("SRT-ORD",'S',{"ASC","DSC"}),
		TagMask("SRT-SLC",'N'),
		TagMask("SRT-DST")
	};
	const std::vector<std::vector<TagMask>> tag_masks = { tag_map,tag_aggregate,tag_sorting };
	void identifyTag(Tag& input);
public:
	bool doesTagExist(Tag& input);
	bool doesTagExist(const Tag& input) const;
	void executeTag(const Tag& input);
};