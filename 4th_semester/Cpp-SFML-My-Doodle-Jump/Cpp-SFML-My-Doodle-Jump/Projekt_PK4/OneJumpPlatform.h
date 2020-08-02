#ifndef ONEJUMPPLATFORM_H
#define ONEJUMPPLATFORM_H
#include "Platform.h"
class OneJumpPlatform : public Platform
{
	bool is_visited = false;
public:
	OneJumpPlatform() = default;
	OneJumpPlatform(float x, float y);
	~OneJumpPlatform();
	bool get_is_visited() const override;
	void set_is_visited(bool is_v) override;
};
#endif // !ONEJUMPPLATFORM_H



