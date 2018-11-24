#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

class SoundManager
{
private:
    int currentSoundTrackIndex = 0;
    bool isPaused = true;
    QMediaPlayer *mainPlayer;
public:
    SoundManager();
    ~SoundManager();

    void NextSoundtrack();
    void PauseCurrent();
    void SetVolume(int vol);

    int getCurrentSoundTrackIndex() const;
    void setCurrentSoundTrackIndex(int value);
    QMediaPlayer *getMainPlayer() const;
    void setMainPlayer(QMediaPlayer *value);
};

#endif // SOUNDMANAGER_H
