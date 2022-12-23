#pragma once
#include "common.h"
// ゲームシーン
class Game : public App::Scene
{
public:

	Game(const InitData& init);

	void update() override;

	void draw() const override;

	void reset();

private:

	int32 m_left_number;
	int32 m_right_number;
	int32 m_answer;
	int32 m_input;
	bool shoud_show_incorrect;
	Texture m_texture;
	int32 m_answer_digit;
	Vec2 m_pos_question;
	Monster m_monster;
	Player m_player;
	double m_time;
};
