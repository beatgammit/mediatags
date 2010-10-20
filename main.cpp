#include <id3/tag.h>
#include <fstream>
#include <math.h>

using namespace std;

void printFrameID(int iID, char* tCharArray, int* iCount){
	switch(iID){
		case ID3FID_NOFRAME:{				// No known frame.
			break;
		}
		case ID3FID_AUDIOCRYPTO:{			// Audio encryption.
			strncat(tCharArray, "\"AENC\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PICTURE:{				// Attached picture.
			strncat(tCharArray, "\"APIC\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COMMENT:{				// Comments.
			strncat(tCharArray, "\"COMM\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COMMERCIAL:{			// Commercial frame.
			strncat(tCharArray, "\"COMR\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CRYPTOREG:{				// Encryption method registration.
			strncat(tCharArray, "\"ENCR\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_EQUALIZATION:{			// Equalization.
			strncat(tCharArray, "\"EQUA\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_EVENTTIMING:{			// Event timing codes.
			strncat(tCharArray, "\"ETCO\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_GENERALOBJECT:{			// General encapsulated object.
			strncat(tCharArray, "\"GEOB\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_GROUPINGREG:{			// Group identification registration.
			strncat(tCharArray, "\"GRID\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_INVOLVEDPEOPLE:{		// Involved people list.
			strncat(tCharArray, "\"IPLS\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LINKEDINFO:{			// Linked information.
			strncat(tCharArray, "\"LINK\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CDID:{					// Music CD identifier.
			strncat(tCharArray, "\"MCDI\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_MPEGLOOKUP:{			// MPEG location lookup table.
			strncat(tCharArray, "\"MLLT\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_OWNERSHIP:{				// Ownership frame.
			strncat(tCharArray, "\"OWNE\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PRIVATE:{				// Private frame.
			strncat(tCharArray, "\"PRIV\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PLAYCOUNTER:{			// Play counter.
			strncat(tCharArray, "\"PCNT\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_POPULARIMETER:{			// Popularimeter.
			strncat(tCharArray, "\"POPM\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_POSITIONSYNC:{			// Position synchronisation frame.
			strncat(tCharArray, "\"POSS\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_BUFFERSIZE:{			// Recommended buffer size.
			strncat(tCharArray, "\"RBUF\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_VOLUMEADJ:{				// Relative volume adjustment.
			strncat(tCharArray, "\"RVAD\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_REVERB:{				// Reverb.
			strncat(tCharArray, "\"RVRB\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SYNCEDLYRICS:{			// Synchronized lyric/text.
			strncat(tCharArray, "\"SYLT\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SYNCEDTEMPO:{			// Synchronized tempo codes.
			strncat(tCharArray, "\"SYTC\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ALBUM:{					// Album/Movie/Show title.
			strncat(tCharArray, "\"TALB\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_BPM:{					// BPM (beats per minute).
			strncat(tCharArray, "\"TBPM\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COMPOSER:{				// Composer.
			strncat(tCharArray, "\"TCOM\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CONTENTTYPE:{			// Content type.
			strncat(tCharArray, "\"TCON\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COPYRIGHT:{				// Copyright message.
			strncat(tCharArray, "\"TCOP\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_DATE:{					// Date.
			strncat(tCharArray, "\"TDAT\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PLAYLISTDELAY:{			// Playlist delay.
			strncat(tCharArray, "\"TDLY\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ENCODEDBY:{				// Encoded by.
			strncat(tCharArray, "\"TENC\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LYRICIST:{				// Lyricist/Text writer.
			strncat(tCharArray, "\"TEXT\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_FILETYPE:{				// File type.
			strncat(tCharArray, "\"TFLT\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TIME:{					// Time.
			strncat(tCharArray, "\"TIME\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CONTENTGROUP:{			// Content group description.
			strncat(tCharArray, "\"TIT1\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TITLE:{					// Title/songname/content description.
			strncat(tCharArray, "\"TIT2\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SUBTITLE:{				// Subtitle/Description refinement.
			strncat(tCharArray, "\"TIT3\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_INITIALKEY:{			// Initial key.
			strncat(tCharArray, "\"TKEY\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LANGUAGE:{				// Language(s).
			strncat(tCharArray, "\"TLAN\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SONGLEN:{				// Length.
			strncat(tCharArray, "\"TLEN\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_MEDIATYPE:{				// Media type.
			strncat(tCharArray, "\"TMED\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGALBUM:{				// Original album/movie/show title.
			strncat(tCharArray, "\"TOAL\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGFILENAME:{			// Original filename.
			strncat(tCharArray, "\"TOFN\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGLYRICIST:{			// Original lyricist(s)/text writer(s).
			strncat(tCharArray, "\"TOLY\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGARTIST:{			// Original artist(s)/performer(s).
			strncat(tCharArray, "\"TOPE\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGYEAR:{				// Original release year.
			strncat(tCharArray, "\"TORY\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_FILEOWNER:{				// File owner/licensee.
			strncat(tCharArray, "\"TOWN\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LEADARTIST:{			// Lead performer(s)/Soloist(s).
			strncat(tCharArray, "\"TPE1\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_BAND:{					// Band/orchestra/accompaniment.
			strncat(tCharArray, "\"TPE2\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CONDUCTOR:{				// Conductor/performer refinement.
			strncat(tCharArray, "\"TPE3\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_MIXARTIST:{				// Interpreted, remixed, or otherwise modified by.
			strncat(tCharArray, "\"TPE4\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PARTINSET:{				// Part of a set.
			strncat(tCharArray, "\"TPOS\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PUBLISHER:{				// Publisher.
			strncat(tCharArray, "\"TPUB\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TRACKNUM:{				// Track number/Position in set.
			strncat(tCharArray, "\"TRCK\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_RECORDINGDATES:{		// Recording dates.
			strncat(tCharArray, "\"TRDA\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_NETRADIOSTATION:{		// Internet radio station name.
			strncat(tCharArray, "\"TRSN\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_NETRADIOOWNER:{			// Internet radio station owner.
			strncat(tCharArray, "\"TRSO\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SIZE:{					// Size.
			strncat(tCharArray, "\"TSIZ\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ISRC:{					// ISRC (international standard recording code).
			strncat(tCharArray, "\"TSRC\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ENCODERSETTINGS:{		// Software/Hardware and settings used for encoding.
			strncat(tCharArray, "\"TSSE\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_USERTEXT:{				// User defined text information.
			strncat(tCharArray, "\"TXXX\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_YEAR:{					// Year.
			strncat(tCharArray, "\"TYER\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_UNIQUEFILEID:{			// Unique file identifier.
			strncat(tCharArray, "\"UFID\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TERMSOFUSE:{			// Terms of use.
			strncat(tCharArray, "\"USER\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_UNSYNCEDLYRICS:{		// Unsynchronized lyric/text transcription.
			strncat(tCharArray, "\"USLT\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWCOMMERCIALINFO:{		// Commercial information.
			strncat(tCharArray, "\"WCOM\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWCOPYRIGHT:{			// Copyright/Legal infromation.
			strncat(tCharArray, "\"WCOP\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWAUDIOFILE:{			// Official audio file webpage.
			strncat(tCharArray, "\"WOAF\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWARTIST:{				// Official artist/performer webpage.
			strncat(tCharArray, "\"WOAR\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWAUDIOSOURCE:{		// Official audio source webpage.
			strncat(tCharArray, "\"WOAS\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWRADIOPAGE:{			// Official internet radio station homepage.
			strncat(tCharArray, "\"WORS\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWPAYMENT:{			// Payment.
			strncat(tCharArray, "\"WPAY\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWPUBLISHER:{			// Official publisher webpage.
			strncat(tCharArray, "\"WPUB\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWUSER:{				// User defined URL link.
			strncat(tCharArray, "\"WXXX\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_METACRYPTO:{			// Encrypted meta frame (id3v2.2.x).
			break;
		}
		case ID3FID_METACOMPRESSION:{		// Compressed meta frame (id3v2.2.1).
			break;
		}
		case ID3FID_LASTFRAMEID:{			// Last field placeholder
			break;
		}
		default:{
			break;
		}
	}
}

bool printID(int iID, char* tCharArray, int* iCount){
	switch(iID){
		case ID3FN_NOFIELD:{			// No field.
			return false;
		}
		case ID3FN_TEXTENC:{			// Text encoding (unicode or ASCII).
			strncat(tCharArray, "\"Text Encoding\"", 15);
			*iCount += 15;
			break;
		}
		case ID3FN_TEXT:{				// Text field.
			strncat(tCharArray, "\"Text Field\"", 12);
			*iCount += 12;
			break;
		}
		case ID3FN_URL:{				// A URL.
			strncat(tCharArray, "\"URL\"", 5);
			*iCount += 5;
			break;
		}
		case ID3FN_DATA:{				// Data field.
			strncat(tCharArray, "\"Data\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FN_DESCRIPTION:{		// Description field.
			strncat(tCharArray, "\"Description\"", 13);
			*iCount += 13;
			break;
		}
		case ID3FN_OWNER:{				// Owner field.
			strncat(tCharArray, "\"Owner\"", 7);
			*iCount += 7;
			break;
		}
		case ID3FN_EMAIL:{				// Email field.
			strncat(tCharArray, "\"Email\"", 7);
			*iCount += 7;
			break;
		}
		case ID3FN_RATING:{				// Rating field.
			strncat(tCharArray, "\"Rating\"", 8);
			*iCount += 8;
			break;
		}
		case ID3FN_FILENAME:{			// Filename field.
			strncat(tCharArray, "\"File Name\"", 11);
			*iCount += 11;
			break;
		}
		case ID3FN_LANGUAGE:{			// Language field.
			strncat(tCharArray, "\"Language\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_PICTURETYPE:{		// Picture type field.
			strncat(tCharArray, "\"Picture Type\"", 14);
			*iCount += 14;
			break;
		}
		case ID3FN_IMAGEFORMAT:{		// Image format field.
			strncat(tCharArray, "\"Image Format\"", 14);
			*iCount += 14;
			break;
		}
		case ID3FN_MIMETYPE:{			// Mimetype field.
			strncat(tCharArray, "\"Mimetype\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_COUNTER:{			// Counter field.
			strncat(tCharArray, "\"Counter\"", 9);
			*iCount += 9;
			break;
		}
		case ID3FN_ID:{					// Identifier/Symbol field.
			strncat(tCharArray, "\"ID/Symbol\"", 11);
			*iCount += 11;
			break;
		}
		case ID3FN_VOLUMEADJ:{			// Volume adjustment field.
			strncat(tCharArray, "\"Vol-adjust\"", 12);
			*iCount += 12;
			break;
		}
		case ID3FN_NUMBITS:{			// Number of bits field.
			strncat(tCharArray, "\"Num-bits\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_VOLCHGRIGHT:{		// Volume chage on the right channel.
			strncat(tCharArray, "\"vol-right\"", 11);
			*iCount += 11;
			break;
		}
		case ID3FN_VOLCHGLEFT:{			// Volume chage on the left channel.
			strncat(tCharArray, "\"Vol-left\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_PEAKVOLRIGHT:{		// Peak volume on the right channel.
			strncat(tCharArray, "\"Peak vol-right\"", 16);
			*iCount += 16;
			break;
		}
		case ID3FN_PEAKVOLLEFT:{		// Peak volume on the left channel.
			strncat(tCharArray, "\"Peak vol-left\"", 15);
			*iCount += 15;
			break;
		}
		case ID3FN_TIMESTAMPFORMAT:{	// SYLT Timestamp Format.
			strncat(tCharArray, "\"Time Stamp\"", 12);
			*iCount += 12;
			break;
		}
		case ID3FN_CONTENTTYPE:{		// SYLT content type.
			strncat(tCharArray, "\"Content Type\"", 14);
			*iCount += 14;
			break;
		}
		case ID3FN_LASTFIELDID:{		// Last field placeholder.
			strncat(tCharArray, "\"Last Field ID\"", 15);
			*iCount += 15;
			break;
		}
	}
	return true;
}

void printme(ID3_Field* tField, char* tCharArray, int* iCount){
	if(printID(tField->GetID(), tCharArray, iCount)){
		strncat(tCharArray, ":", 1);
		*iCount += 1;

		switch(tField->GetType()){
			case ID3FTY_INTEGER:{
				sprintf(tCharArray, "%s%d", tCharArray, tField->Get());
				if(tField->Get() >= 10){
					*iCount += (int)log10(tField->Get()) + 1;
				}else{
					*iCount += 1;
				}
				break;
			}
			case ID3FTY_BINARY:{
				strncat(tCharArray, "\"", 1);
				strncat(tCharArray, "Woohoo, we have stuff", 21);
				strncat(tCharArray, "\"", 1);
				*iCount += 21 + 2;
				break;
			}
			case ID3FTY_TEXTSTRING:{
				strncat(tCharArray, "\"", 1);
				strncat(tCharArray, tField->GetRawText(), tField->Size());
				strncat(tCharArray, "\"", 1);
				*iCount = strlen(tCharArray); // for some reason we keep getting weird results here
				//*iCount += tField->Size() + 2; // size of the text plus the two quotes we put around it
				break;
			}
			case ID3FTY_NUMTYPES:{
				break;
			}
			case ID3FTY_NONE:
			default:{
				break;
			}
		}
	}
}

int main()
{
	ID3_Tag myTag("/home/jameson/Desktop/yellow-card-believe.mp3");
	cout << myTag.GetFileName() << endl;

	cout << "Size: " << myTag.Size() << endl << endl;

	char* tCharArray = new char[myTag.Size()];
	tCharArray[0] = 0;
	int iCount = 0;

	// add the initial curly brace for JSON output
	strncat(tCharArray, "{", 1);
	iCount += 1;

	ID3_Tag::Iterator *iter = myTag.CreateIterator();
	ID3_Frame *myFrame = NULL;
	while(NULL != (myFrame = iter->GetNext())){
		printFrameID(myFrame->GetID(), tCharArray, &iCount);

		strncat(tCharArray, ":{", 2);
		iCount += 2;

		ID3_Frame::Iterator* fieldIter = myFrame->CreateIterator();
		ID3_Field* tField = NULL;
		while(NULL != (tField = fieldIter->GetNext())){
			printme(tField, tCharArray, &iCount);

			strncat(tCharArray, ",", 1);
			iCount += 1;
		}
		tCharArray[iCount - 1] = '}'; // gets rid of the trailing comma
	}

	// add the trailing JSON curly brace
	strncat(tCharArray, "}\n", 2);
	iCount += 2;

	cout << "Here's the frame stuff:" << endl;
	cout << "Count: " << iCount << endl;
	cout << "strlen: " << strlen(tCharArray) << endl;
	cout << "Size of array: " << myTag.Size() << endl << endl;
	cout << tCharArray;
	delete tCharArray;

	return 0;
}
