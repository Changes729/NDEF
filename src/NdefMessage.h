#ifndef NdefMessage_h
#define NdefMessage_h

#include <Ndef.h>
#include <NdefRecord.h>

#define MAX_NDEF_RECORDS 4

class NdefMessage {
public:
  NdefMessage(void);
  NdefMessage(const byte *data, const int numBytes);
  NdefMessage(const NdefMessage &rhs);
  virtual ~NdefMessage();
  NdefMessage &operator=(const NdefMessage &rhs);

  int getEncodedSize() const; // need so we can pass array to encode
  void encode(byte *data);

  boolean addRecord(NdefRecord &record);
  void addMimeMediaRecord(String mimeType, String payload);
  void addMimeMediaRecord(String mimeType, byte *payload, int payloadLength);
  void addTextRecord(String text);
  void addTextRecord(String text, String encoding);
  void addUriRecord(String uri);
  void addEmptyRecord();

  unsigned int getRecordCount() const;
  const NdefRecord *getRecord(int index) const;
  const NdefRecord &operator[](int index) const;

#ifdef NDEF_USE_SERIAL
  void print() const;
#endif

private:
  NdefRecord _records[MAX_NDEF_RECORDS];
  unsigned int _recordCount;
};

#endif