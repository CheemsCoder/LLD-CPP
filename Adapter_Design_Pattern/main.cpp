#include <iostream>
#include <string>
using namespace std;

/*
================================= ADAPTER DESIGN PATTERN =================================

**Theory:**
The Adapter Pattern bridges the gap between two incompatible interfaces, allowing them to work together.
It converts the interface of one class (Adaptee) into an interface expected by the client (Target).

**Real-Life Example:**
Imagine using a power adapter to plug a device with a specific type of plug (Adaptee) into a power outlet
(Target) with a different type of socket.

**UML Diagram Explanation:**
1. **Target (MediaPlayer):** Defines the interface expected by the client (e.g., `play(audioType, fileName)`).
2. **Adaptee (AdvancedMediaPlayer):** Represents the incompatible interface to be adapted (e.g., `playMP4`, `playVLC`).
3. **Adapter (MediaAdapter):** Bridges the gap by implementing the Target interface and using the Adaptee's methods.
4. **Concrete Adaptees (MP4Player, VLCPlayer):** Provide the specific implementations of the Adaptee interface.
5. **Client (AudioPlayer):** Works with the Target interface (MediaPlayer).

==========================================================================================
*/

/// Target Interface: The interface the client expects
class MediaPlayer {
  public:
    virtual void play(string audioType, string fileName) = 0; // Expected method
};

/// Adaptee Interface: The existing incompatible interface
class AdvancedMediaPlayer {
  public:
    virtual void playMP4(string fileName) = 0;
    virtual void playVLC(string fileName) = 0;
};

/// Concrete Adaptee: Implements the Adaptee interface for VLC
class VLCPlayer : public AdvancedMediaPlayer {
  public:
    void playMP4(string fileName) {
        // Do nothing
    }
    void playVLC(string fileName) {
        cout << "Playing VLC file: " << fileName << endl;
    }
};

/// Concrete Adaptee: Implements the Adaptee interface for MP4
class MP4Player : public AdvancedMediaPlayer {
  public:
    void playMP4(string fileName) {
        cout << "Playing MP4 file: " << fileName << endl;
    }
    void playVLC(string fileName) {
        // Do nothing
    }
};

/// Adapter: Bridges the Target and Adaptee interfaces
class MediaAdapter : public MediaPlayer {
  private:
    AdvancedMediaPlayer* advancedPlayer; // Composition: Uses an Adaptee
  public:
    MediaAdapter(string audioType) {
        if (audioType == "vlc") {
            advancedPlayer = new VLCPlayer(); // Create VLCPlayer for VLC files
        } else if (audioType == "mp4") {
            advancedPlayer = new MP4Player(); // Create MP4Player for MP4 files
        }
    }
    void play(string audioType, string fileName) {
        if (audioType == "vlc") {
            advancedPlayer->playVLC(fileName); // Delegate to the Adaptee
        } else if (audioType == "mp4") {
            advancedPlayer->playMP4(fileName); // Delegate to the Adaptee
        }
    }
    ~MediaAdapter() {
        delete advancedPlayer; // Clean up dynamically allocated memory
    }
};

/// Client: Works with the Target interface
class AudioPlayer : public MediaPlayer {
  public:
    void play(string audioType, string fileName) {
        if (audioType == "mp3") {
            cout << "Playing MP3 file: " << fileName << endl; // Directly supported
        } else if (audioType == "vlc" || audioType == "mp4") {
            MediaAdapter* adapter = new MediaAdapter(audioType); // Use Adapter for unsupported types
            adapter->play(audioType, fileName);
            delete adapter; // Clean up the Adapter
        } else {
            cout << "Invalid media type: " << audioType << endl; // Unsupported type
        }
    }
};

/// Main Function: Demonstrates the Adapter Pattern
int main() {
    AudioPlayer* player = new AudioPlayer();

    // Test playing different media types
    player->play("mp3", "song.mp3");       // Directly supported by AudioPlayer
    player->play("mp4", "video.mp4");      // Requires Adapter
    player->play("vlc", "movie.vlc");      // Requires Adapter
    player->play("avi", "clip.avi");       // Unsupported media type

    delete player; // Clean up
    return 0;
}

/*
================================ UML DIAGRAM =================================

[Client] (AudioPlayer) ---> [Target Interface] (MediaPlayer)
    |                            ^
    |                            |
    |                            |
    -----> [Adapter] (MediaAdapter) ---> [Adaptee Interface] (AdvancedMediaPlayer)
                                         ^               ^
                                         |               |
                              [Concrete Adaptees]   [Concrete Adaptees]
                               (VLCPlayer)            (MP4Player)

================================================================================
*/
