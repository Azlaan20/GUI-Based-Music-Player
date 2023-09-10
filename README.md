# Music Player C++ Project

This is a C++ project to create a music player application. It utilizes the Windows multimedia API (MCI) to play MP3 files.

## Features

- Play/pause/stop MP3 files
- Next/previous track controls
- Shuffle and repeat modes
- Mount/unmount USB drives to load music library 
- Save/load playlists
- Search for songs

## Classes

The main classes are:

- `AudioPlayer`: Handles mounting drives, checking free space etc.
- `Song`: Represents a song, handles playback controls. 
- `AudioPlayerV2`: Extends AudioPlayer and Song to add playlist functionality.

Key methods:

- `PlaySong()`: Starts playback of a song
- `PauseSong()`: Pauses current song
- `NextSong()`: Plays next song in library or playlist
- `PreviousSong()`: Plays previous song
- `AddSongToPlaylist()`: Adds currently playing song to playlist
- `SavePlaylist()`: Saves playlist to file
- `LoadPlaylist()`: Loads playlist from file

## Usage

The `MyForm` Windows form provides a GUI for the music player. It allows:

- Toggling between File Mode and Playlist Mode
- Controlling playback
- Managing playlists
- Searching for songs

The underlying `AudioPlayer`, `Song` and `AudioPlayerV2` classes can also be used in a console app.

## Build Requirements

- Microsoft Visual Studio
- Windows SDK for MCI API
