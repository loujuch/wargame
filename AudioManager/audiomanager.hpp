#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QList>
#include <QPair>

#include "audiomessage.hpp"

enum AudioType {BGM, TALK};

class AudioManager {
	float bgm_volume_;
	QMediaPlayer bgm_player_;
	QAudioOutput bgm_output_;
	QList<QPair<QList<QString>, QString>> bgm_;

	float talk_volume_;
	QMediaPlayer talk_player_;
	QAudioOutput talk_output_;
	QList<QString> talk_;
  public:
	AudioManager();

  public slots:
	void changeVolume(float change, enum AudioType type);
	void switchAudio(const AudioMessage &message);
	void switchBgm(int index);
	void playTalk(int index);
};

#endif // AUDIOMANAGER_HPP
