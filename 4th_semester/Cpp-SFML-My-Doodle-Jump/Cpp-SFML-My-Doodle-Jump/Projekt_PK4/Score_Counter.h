#ifndef SCORE_COUNTER_H
#define SCORE_COUNTER_H
#include <string>
class Score_Counter
{
	static int highscore;
	float current_score, current_highscore;
public:
	Score_Counter();
	~Score_Counter() = default;
	float get_cur_score() const;
	void set_cur_score(float c_s);

	static int get_highscore();
	void load_highscore(std::string filename);
	void save_highscore(std::string filename);
};
#endif // !SCORE_COUNTER_H