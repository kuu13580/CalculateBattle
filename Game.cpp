#include "common.h"
#include "Game.h"

Emoji emojis[] = { U"🐕"_emoji , U"🐈"_emoji, U"🦁"_emoji, U"🐀"_emoji, U"🐄"_emoji, U"🐉"_emoji };

Game::Game(const InitData& init)
	: IScene{ init }
	, m_input(0)
{
	m_monster = getData().monsters.at(getData().selected_monster);
	m_player = getData().player;
	m_texture = Texture(emojis[getData().selected_monster]);
	reset();
}

void Game::update() {
	if (m_monster.hp <= 0) {
		// クリアシーンに移動
		changeScene(U"Clear");
	}
	if (SimpleGUI::Button(get_text(U"TXT_FINISH_BTN", getData().lang, getData().texts), Vec2{ 10, 10 }, 100))
	{
		// タイトルシーンに遷移
		changeScene(U"Title");
	}
	if (SimpleGUI::Button(get_text(U"TXT_LANGUAGE", Language((getData().lang + 1) % (Language::Language_MAX + 1)), getData().texts), Vec2{ 120, 10 }, 100))
	{
		// 言語変更
		getData().lang = Language((getData().lang + 1) % (Language::Language_MAX + 1));
	}
	if (SimpleGUI::Button(get_text(U"TXT_CHANGE", getData().lang, getData().texts), Vec2{ 20, 440 }, 200))
	{
		// 敵変更
		getData().selected_monster = (getData().selected_monster + 1) % (int32)getData().monsters.size();
		changeScene(U"Game");
	}
	// キー入力があった
	if (Key0.down()) m_input = (m_input * 10 + 0) % MAX_DIGIT;
	if (Key1.down()) m_input = (m_input * 10 + 1) % MAX_DIGIT;
	if (Key2.down()) m_input = (m_input * 10 + 2) % MAX_DIGIT;
	if (Key3.down()) m_input = (m_input * 10 + 3) % MAX_DIGIT;
	if (Key4.down()) m_input = (m_input * 10 + 4) % MAX_DIGIT;
	if (Key5.down()) m_input = (m_input * 10 + 5) % MAX_DIGIT;
	if (Key6.down()) m_input = (m_input * 10 + 6) % MAX_DIGIT;
	if (Key7.down()) m_input = (m_input * 10 + 7) % MAX_DIGIT;
	if (Key8.down()) m_input = (m_input * 10 + 8) % MAX_DIGIT;
	if (Key9.down()) m_input = (m_input * 10 + 9) % MAX_DIGIT;
	if (KeyBackspace.down()) m_input /= 10;
	if (KeySpace.down()) { //正誤判定
		if (m_input % (int)pow(10, m_answer_digit) == m_answer) {
			// 攻撃を受ける
			m_monster.hp -= m_player.ap / (m_monster.dp / 100.0);
			reset();
		}
		else {
			m_input = 0;
		}
	}
	// 下に到達
	if (m_pos_question.y > 500) {
		m_player.hp -= m_monster.ap;
		reset();
		if (m_player.hp <= 0) changeScene(U"GameOver");;
	}
	m_pos_question.y = m_monster.speed * m_time;
	m_time += Scene::DeltaTime();
}

void Game::draw() const
{
	Scene::SetBackground(ColorF(0.2, 0.8, 0.6));
	m_texture.drawAt(Vec2{ 100, 120 });
	Rect{ 0, 500, 800, 600 }.draw();
	// 表示
	// 問題
	FontAsset(U"Question")(Format(m_left_number) + U"+" + Format(m_right_number)).draw(m_pos_question);
	// 入力値
	FontAsset(U"ScoreFont")(get_text(U"TXT_INPUT", getData().lang, getData().texts) + U" : " + Format(m_input)).draw(200, 510, Palette::Black);
	FontAsset(U"ScoreFont")(get_text(U"TXT_HP", getData().lang, getData().texts) + U" : " + Format(m_player.hp)).draw(200, 550, Palette::Black);
	// データ
	String data = get_text(m_monster.name_id, getData().lang, getData().texts) + U"\n"
		+ get_text(U"TXT_HP", getData().lang, getData().texts) + Format(m_monster.hp) + U"\n"
		+ get_text(U"TXT_ATTACK", getData().lang, getData().texts) + Format(m_monster.ap) + U"\n"
		+ get_text(U"TXT_DEFENCE", getData().lang, getData().texts) + Format(m_monster.dp) + U"\n"
		+ get_text(U"TXT_SPEED", getData().lang, getData().texts) + Format(m_monster.speed);
	FontAsset(U"ScoreFont")(data).draw(30, 200, Palette::Black);
	FontAsset(U"Explain")(get_text(U"TXT_HOW_ANSWER", getData().lang, getData().texts)).draw(430, 530, Palette::Black);
}

void Game::reset() {
	m_left_number = Random(2, 99);
	m_right_number = Random(2, 99);
	m_answer = m_left_number + m_right_number;
	m_answer_digit = Format(m_answer).size();
	m_pos_question = { 350, 0 };
	m_input = 0;
	m_time = 0;
}
