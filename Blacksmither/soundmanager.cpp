#include "soundmanager.h"

int SoundManager::getCurrentSoundTrackIndex() const
{
    return currentSoundTrackIndex;
}

void SoundManager::setCurrentSoundTrackIndex(int value)
{
    currentSoundTrackIndex = value;
}

QMediaPlayer *SoundManager::getMainPlayer() const
{
    return mainPlayer;
}

void SoundManager::setMainPlayer(QMediaPlayer *value)
{
    mainPlayer = value;
}

SoundManager::SoundManager(){
    mainPlayer = new QMediaPlayer();
    gameMusic = new QMediaPlaylist();

    gameMusic->addMedia(QUrl("qrc:/WAV/medieval-music-french-folk.mp3"));
    gameMusic->addMedia(QUrl("qrc:/WAV/medieval-music-italian-salta.mp3"));
    gameMusic->addMedia(QUrl("qrc:/WAV/medieval-tavern-music-by.mp3"));

    gameMusic->setPlaybackMode(QMediaPlaylist::Loop);
    gameMusic->setCurrentIndex(1);
    mainPlayer->setPlaylist(gameMusic);
    mainPlayer->play();
}

SoundManager::~SoundManager(){

}

void SoundManager::ResetPlayList(){
    mainPlayer->pause();
    mainPlayer->setPlaylist(gameMusic);
    gameMusic->setCurrentIndex(1);
    if(!isPaused)
        mainPlayer->play();
}

void SoundManager::NextSoundtrack(){
    mainPlayer->playlist()->next();
    if(mainPlayer->playlist()->currentIndex() > mainPlayer->playlist()->mediaCount()){
        mainPlayer->playlist()->setCurrentIndex(1);
    }
}

void SoundManager::PauseCurrent(){
    if(!isPaused){
        mainPlayer->pause();
        isPaused = true;
    }else{
        mainPlayer->play();
        isPaused = false;
    }
}

void SoundManager::SetVolume(int vol){
    mainPlayer->setVolume(vol);
}
