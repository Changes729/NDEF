#ifndef NdefRecord_h
#define NdefRecord_h

#include <Arduino.h>
#include <Ndef.h>

#define TNF_EMPTY 0x0
#define TNF_WELL_KNOWN 0x01
#define TNF_MIME_MEDIA 0x02
#define TNF_ABSOLUTE_URI 0x03
#define TNF_EXTERNAL_TYPE 0x04
#define TNF_UNKNOWN 0x05
#define TNF_UNCHANGED 0x06
#define TNF_RESERVED 0x07

class NdefRecord {
public:
  NdefRecord();
  NdefRecord(const NdefRecord &rhs);
  ~NdefRecord();
  NdefRecord &operator=(const NdefRecord &rhs);

  int getEncodedSize() const;
  void encode(byte *data, bool firstRecord, bool lastRecord);

  unsigned int getTypeLength() const;
  int getPayloadLength() const;
  unsigned int getIdLength() const;

  byte getTnf() const;
  void getType(byte *type) const;
  const byte *getPayload() const;
  void getId(byte *id) const;

  // convenience methods
  String getType() const;
  String getId() const;

  void setTnf(byte tnf);
  void setType(const byte *type, const unsigned int numBytes);
  void setPayload(const byte *payload, const int numBytes);
  void setId(const byte *id, const unsigned int numBytes);

#ifdef NDEF_USE_SERIAL
  void print() const;
#endif
private:
  byte getTnfByte(bool firstRecord, bool lastRecord) const;
  byte _tnf; // 3 bit
  unsigned int _typeLength;
  int _payloadLength;
  unsigned int _idLength;
  byte *_type;
  byte *_payload;
  byte *_id;
};

#endif