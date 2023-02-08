#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QList>
#include <QPair>
#include <QJsonObject>


enum AUDIO_TYPE {BGM, TALK};

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
	void changeVolume(float change, enum AUDIO_TYPE type);
	void switchAudio(const QJsonObject &message);
	void switchBgm(int index);
	void playTalk(int index);
};

#endif // AUDIOMANAGER_HPP
