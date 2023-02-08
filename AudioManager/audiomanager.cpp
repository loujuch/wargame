#include "audiomanager.hpp"

AudioManager::AudioManager()
	: bgm_volume_(0.5),
	  talk_volume_(0.5) {
	bgm_player_.setAudioOutput(&bgm_output_);
	talk_player_.setAudioOutput(&talk_output_);

	bgm_output_.setVolume(bgm_volume_);
	talk_output_.setVolume(talk_volume_);
}

void AudioManager::switchAudio(const QJsonObject &message) {

}

void AudioManager::changeVolume(float change, enum AudioType type) {
	switch(type) {
	case AUDIO_TYPE::BGM:
		bgm_volume_ += change;
		bgm_output_.setVolume(bgm_volume_);
		break;

	case AUDIO_TYPE::TALK:
		talk_volume_ += change;
		talk_output_.setVolume(talk_volume_);
		break;
	}
}

void AudioManager::switchBgm(int index) {
	if(index >= bgm_.size()) {
		return;
	}

	bgm_player_.stop();

}


void AudioManager::playTalk(int index) {
	if(index >= talk_.size()) {
		return;
	}
}
