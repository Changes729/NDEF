# NDEF Library for Arduino

Read and Write NDEF messages on NFC Tags with Arduino.

NFC Data Exchange Format (NDEF) is a common data format that operates across all NFC devices, regardless of the underlying tag or device technology.

### Supports
 - translate RFID bytes to NDEF records.
 -
## Getting Started

### NfcTag

Reading a tag with the shield, returns a NfcTag object. The NfcTag object contains meta data about the tag UID, technology, size.  When an NDEF tag is read, the NfcTag object contains a NdefMessage.

### NdefMessage

A NdefMessage consist of one or more NdefRecords.

The NdefMessage object has helper methods for adding records.

    ndefMessage.addTextRecord("hello, world");
    ndefMessage.addUriRecord("http://arduino.cc");

The NdefMessage object is responsible for encoding NdefMessage into bytes so it can be written to a tag. The NdefMessage also decodes bytes read from a tag back into a NdefMessage object.

### NdefRecord

A NdefRecord carries a payload and info about the payload within a NdefMessage.

### Specifications

This code is based on the "NFC Data Exchange Format (NDEF) Technical Specification" and the "Record Type Definition Technical Specifications" that can be downloaded from the [NFC Forum](http://www.nfc-forum.org/specs/spec_license).

### Tests

To run the tests, you'll need [ArduinoUnit](https://github.com/mmurdoch/arduinounit). To "install", I clone the repo to my home directory and symlink the source into ~/Documents/Arduino/libraries/ArduinoUnit.

    $ cd ~
    $ git clone git@github.com:mmurdoch/arduinounit.git
    $ cd ~/Documents/Arduino/libraries/
    $ ln -s ~/arduinounit/src ArduinoUnit

Tests can be run on an Uno without a NFC shield, since the NDEF logic is what is being tested.

## Warning

This software is in development. It works for the happy path. Error handling could use improvement. It runs out of memory, especially on the Uno board. Use small messages with the Uno. The Due board can write larger messages. Please submit patches.

## Book
Need more info? Check out my book <a href="http://www.anrdoezrs.net/click-7521423-11260198-1430755877000?url=http%3A%2F%2Fshop.oreilly.com%2Fproduct%2F0636920021193.do%3Fcmp%3Daf-prog-books-videos-product_cj_9781449372064_%2525zp&cjsku=0636920021193" target="_top">
Beginning NFC: Near Field Communication with Arduino, Android, and PhoneGap</a><img src="http://www.lduhtrp.net/image-7521423-11260198-1430755877000" width="1" height="1" border="0"/>.

<a href="http://www.tkqlhce.com/click-7521423-11260198-1430755877000?url=http%3A%2F%2Fshop.oreilly.com%2Fproduct%2F0636920021193.do%3Fcmp%3Daf-prog-books-videos-product_cj_9781449372064_%2525zp&cjsku=0636920021193" target="_top"><img src="http://akamaicovers.oreilly.com/images/0636920021193/cat.gif" border="0" alt="Beginning NFC"/></a><img src="http://www.awltovhc.com/image-7521423-11260198-1430755877000" width="1" height="1" border="0"/>

## License

[BSD License](https://github.com/Changes729/Ndef/blob/master/LICENSE.txt) (c) 2024-2026, Ankh