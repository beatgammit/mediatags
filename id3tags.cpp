#include <id3/tag.h>
#include <fstream>
#include <math.h>

using namespace std;

char* destPath = NULL;
char* filePath = NULL;
int iAttachmentNum = 1;

// formats the frame id according to ID3 standard naming convention, but lower-case
void printFrameID(int iID, char* tCharArray, int* iCount){
	switch(iID){
		case ID3FID_NOFRAME:{				// No known frame.
			break;
		}
		case ID3FID_AUDIOCRYPTO:{			// Audio encryption.
			strncat(tCharArray, "\"aenc\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PICTURE:{				// Attached picture.
			strncat(tCharArray, "\"apic\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COMMENT:{				// Comments.
			strncat(tCharArray, "\"comm\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COMMERCIAL:{			// Commercial frame.
			strncat(tCharArray, "\"comr\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CRYPTOREG:{				// Encryption method registration.
			strncat(tCharArray, "\"encr\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_EQUALIZATION:{			// Equalization.
			strncat(tCharArray, "\"equa\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_EVENTTIMING:{			// Event timing codes.
			strncat(tCharArray, "\"etco\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_GENERALOBJECT:{			// General encapsulated object.
			strncat(tCharArray, "\"geob\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_GROUPINGREG:{			// Group identification registration.
			strncat(tCharArray, "\"grid\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_INVOLVEDPEOPLE:{		// Involved people list.
			strncat(tCharArray, "\"ipls\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LINKEDINFO:{			// Linked information.
			strncat(tCharArray, "\"link\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CDID:{					// Music CD identifier.
			strncat(tCharArray, "\"mcdi\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_MPEGLOOKUP:{			// MPEG location lookup table.
			strncat(tCharArray, "\"mllt\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_OWNERSHIP:{				// Ownership frame.
			strncat(tCharArray, "\"owne\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PRIVATE:{				// Private frame.
			strncat(tCharArray, "\"priv\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PLAYCOUNTER:{			// Play counter.
			strncat(tCharArray, "\"pcnt\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_POPULARIMETER:{			// Popularimeter.
			strncat(tCharArray, "\"popm\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_POSITIONSYNC:{			// Position synchronisation frame.
			strncat(tCharArray, "\"poss\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_BUFFERSIZE:{			// Recommended buffer size.
			strncat(tCharArray, "\"rbuf\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_VOLUMEADJ:{				// Relative volume adjustment.
			strncat(tCharArray, "\"rvad\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_REVERB:{				// Reverb.
			strncat(tCharArray, "\"rvrb\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SYNCEDLYRICS:{			// Synchronized lyric/text.
			strncat(tCharArray, "\"sylt\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SYNCEDTEMPO:{			// Synchronized tempo codes.
			strncat(tCharArray, "\"sytc\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ALBUM:{					// Album/Movie/Show title.
			strncat(tCharArray, "\"talb\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_BPM:{					// BPM (beats per minute).
			strncat(tCharArray, "\"tbpm\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COMPOSER:{				// Composer.
			strncat(tCharArray, "\"tcom\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CONTENTTYPE:{			// Content type.
			strncat(tCharArray, "\"tcon\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_COPYRIGHT:{				// Copyright message.
			strncat(tCharArray, "\"tcop\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_DATE:{					// Date.
			strncat(tCharArray, "\"tdat\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PLAYLISTDELAY:{			// Playlist delay.
			strncat(tCharArray, "\"tdly\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ENCODEDBY:{				// Encoded by.
			strncat(tCharArray, "\"tenc\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LYRICIST:{				// Lyricist/Text writer.
			strncat(tCharArray, "\"text\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_FILETYPE:{				// File type.
			strncat(tCharArray, "\"tflt\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TIME:{					// Time.
			strncat(tCharArray, "\"time\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CONTENTGROUP:{			// Content group description.
			strncat(tCharArray, "\"tit1\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TITLE:{					// Title/songname/content description.
			strncat(tCharArray, "\"tit2\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SUBTITLE:{				// Subtitle/Description refinement.
			strncat(tCharArray, "\"tit3\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_INITIALKEY:{			// Initial key.
			strncat(tCharArray, "\"tkey\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LANGUAGE:{				// Language(s).
			strncat(tCharArray, "\"tlan\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SONGLEN:{				// Length.
			strncat(tCharArray, "\"tlen\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_MEDIATYPE:{				// Media type.
			strncat(tCharArray, "\"tmed\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGALBUM:{				// Original album/movie/show title.
			strncat(tCharArray, "\"toal\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGFILENAME:{			// Original filename.
			strncat(tCharArray, "\"tofn\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGLYRICIST:{			// Original lyricist(s)/text writer(s).
			strncat(tCharArray, "\"toly\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGARTIST:{			// Original artist(s)/performer(s).
			strncat(tCharArray, "\"tope\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ORIGYEAR:{				// Original release year.
			strncat(tCharArray, "\"tory\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_FILEOWNER:{				// File owner/licensee.
			strncat(tCharArray, "\"town\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_LEADARTIST:{			// Lead performer(s)/Soloist(s).
			strncat(tCharArray, "\"tpe1\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_BAND:{					// Band/orchestra/accompaniment.
			strncat(tCharArray, "\"tpe2\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_CONDUCTOR:{				// Conductor/performer refinement.
			strncat(tCharArray, "\"tpe3\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_MIXARTIST:{				// Interpreted, remixed, or otherwise modified by.
			strncat(tCharArray, "\"tpe4\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PARTINSET:{				// Part of a set.
			strncat(tCharArray, "\"tpos\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_PUBLISHER:{				// Publisher.
			strncat(tCharArray, "\"tpub\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TRACKNUM:{				// Track number/Position in set.
			strncat(tCharArray, "\"trck\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_RECORDINGDATES:{		// Recording dates.
			strncat(tCharArray, "\"trda\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_NETRADIOSTATION:{		// Internet radio station name.
			strncat(tCharArray, "\"trsn\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_NETRADIOOWNER:{			// Internet radio station owner.
			strncat(tCharArray, "\"trso\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_SIZE:{					// Size.
			strncat(tCharArray, "\"tsiz\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ISRC:{					// ISRC (international standard recording code).
			strncat(tCharArray, "\"tsrc\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_ENCODERSETTINGS:{		// Software/Hardware and settings used for encoding.
			strncat(tCharArray, "\"tsse\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_USERTEXT:{				// User defined text information.
			strncat(tCharArray, "\"txxx\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_YEAR:{					// Year.
			strncat(tCharArray, "\"tyer\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_UNIQUEFILEID:{			// Unique file identifier.
			strncat(tCharArray, "\"ufid\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_TERMSOFUSE:{			// Terms of use.
			strncat(tCharArray, "\"user\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_UNSYNCEDLYRICS:{		// Unsynchronized lyric/text transcription.
			strncat(tCharArray, "\"uslt\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWCOMMERCIALINFO:{		// Commercial information.
			strncat(tCharArray, "\"wcom\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWCOPYRIGHT:{			// Copyright/Legal infromation.
			strncat(tCharArray, "\"wcop\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWAUDIOFILE:{			// Official audio file webpage.
			strncat(tCharArray, "\"woaf\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWARTIST:{				// Official artist/performer webpage.
			strncat(tCharArray, "\"woar\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWAUDIOSOURCE:{		// Official audio source webpage.
			strncat(tCharArray, "\"woas\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWRADIOPAGE:{			// Official internet radio station homepage.
			strncat(tCharArray, "\"wors\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWPAYMENT:{			// Payment.
			strncat(tCharArray, "\"wpay\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWPUBLISHER:{			// Official publisher webpage.
			strncat(tCharArray, "\"wpub\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FID_WWWUSER:{				// User defined URL link.
			strncat(tCharArray, "\"wxxx\"", 6);
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

// prints the field id according to the last part of the constant that ID3 uses but lowercase, eg ID3FN_FIELDID -> fieldid
bool printID(int iID, char* tCharArray, int* iCount){
	switch(iID){
		case ID3FN_NOFIELD:{			// No field.
			return false;
		}
		case ID3FN_TEXTENC:{			// Text encoding (unicode or ASCII).
			strncat(tCharArray, "\"textenc\"", 15);
			*iCount += 15;
			break;
		}
		case ID3FN_TEXT:{				// Text field.
			strncat(tCharArray, "\"text\"", 12);
			*iCount += 12;
			break;
		}
		case ID3FN_URL:{				// A URL.
			strncat(tCharArray, "\"url\"", 5);
			*iCount += 5;
			break;
		}
		case ID3FN_DATA:{				// Data field.
			strncat(tCharArray, "\"data\"", 6);
			*iCount += 6;
			break;
		}
		case ID3FN_DESCRIPTION:{		// Description field.
			strncat(tCharArray, "\"description\"", 13);
			*iCount += 13;
			break;
		}
		case ID3FN_OWNER:{				// Owner field.
			strncat(tCharArray, "\"owner\"", 7);
			*iCount += 7;
			break;
		}
		case ID3FN_EMAIL:{				// Email field.
			strncat(tCharArray, "\"email\"", 7);
			*iCount += 7;
			break;
		}
		case ID3FN_RATING:{				// Rating field.
			strncat(tCharArray, "\"rating\"", 8);
			*iCount += 8;
			break;
		}
		case ID3FN_FILENAME:{			// Filename field.
			strncat(tCharArray, "\"file Name\"", 11);
			*iCount += 11;
			break;
		}
		case ID3FN_LANGUAGE:{			// Language field.
			strncat(tCharArray, "\"language\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_PICTURETYPE:{		// Picture type field.
			strncat(tCharArray, "\"picturetype\"", 14);
			*iCount += 14;
			break;
		}
		case ID3FN_IMAGEFORMAT:{		// Image format field.
			strncat(tCharArray, "\"imageformat\"", 14);
			*iCount += 14;
			break;
		}
		case ID3FN_MIMETYPE:{			// Mimetype field.
			strncat(tCharArray, "\"mimetype\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_COUNTER:{			// Counter field.
			strncat(tCharArray, "\"counter\"", 9);
			*iCount += 9;
			break;
		}
		case ID3FN_ID:{					// Identifier/Symbol field.
			strncat(tCharArray, "\"id\"", 11);
			*iCount += 11;
			break;
		}
		case ID3FN_VOLUMEADJ:{			// Volume adjustment field.
			strncat(tCharArray, "\"volumeadj\"", 12);
			*iCount += 12;
			break;
		}
		case ID3FN_NUMBITS:{			// Number of bits field.
			strncat(tCharArray, "\"numbits\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_VOLCHGRIGHT:{		// Volume chage on the right channel.
			strncat(tCharArray, "\"volchgright\"", 11);
			*iCount += 11;
			break;
		}
		case ID3FN_VOLCHGLEFT:{			// Volume chage on the left channel.
			strncat(tCharArray, "\"volchgleft\"", 10);
			*iCount += 10;
			break;
		}
		case ID3FN_PEAKVOLRIGHT:{		// Peak volume on the right channel.
			strncat(tCharArray, "\"peakvolright\"", 16);
			*iCount += 16;
			break;
		}
		case ID3FN_PEAKVOLLEFT:{		// Peak volume on the left channel.
			strncat(tCharArray, "\"peakvolleft\"", 15);
			*iCount += 15;
			break;
		}
		case ID3FN_TIMESTAMPFORMAT:{	// SYLT Timestamp Format.
			strncat(tCharArray, "\"timestampformat\"", 12);
			*iCount += 12;
			break;
		}
		case ID3FN_CONTENTTYPE:{		// SYLT content type.
			strncat(tCharArray, "\"contenttype\"", 14);
			*iCount += 14;
			break;
		}
		case ID3FN_LASTFIELDID:{		// Last field placeholder.
			strncat(tCharArray, "\"lastfieldid\"", 15);
			*iCount += 15;
			break;
		}
	}
	return true;
}

char* getFileName(char* tFilePath, int iAddon){
	char* tFileName = strrchr(tFilePath, '/') + sizeof(char);
	int extLength = strlen(strstr(tFileName, "."));

	int fileNameLength = strlen(tFileName);
	int addonLength = log10(iAddon) + 1;

	// the size of this array will be: length of file name + length of number addon + length of extension + terminating null
	char* newFileName = new char[fileNameLength + addonLength + 5];
	newFileName[0] = 0;

	// copy everything but the extension
	strncat(newFileName, tFileName, fileNameLength - extLength);

	// add in the addon number
	sprintf(newFileName, "%s%d", newFileName, iAddon);

	strncat(newFileName, ".jpg", 4);

	return newFileName;
}

char* getNewFilePath(char* tPath, char* fileName){
	char* newPath = NULL;

	int totalLength = strlen(tPath) + strlen(fileName);
	if(tPath[strlen(tPath) - 1] != '/'){
		totalLength += 1;

		newPath = new char[totalLength];
		sprintf(newPath, "%s/%s", tPath, fileName);
	}else{
		newPath = new char[totalLength];
		newPath[0] = 0;
		sprintf(newPath, "%s%s", tPath, fileName);
	}

	return newPath;
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
				char* tNewFilePath = getNewFilePath(destPath, getFileName(filePath, iAttachmentNum));
				iAttachmentNum++;
				ofstream tFile(tNewFilePath);
				if(tFile){
					tFile.close();

					tField->ToFile(tNewFilePath);

					strncat(tCharArray, "\"", 1);
					strncat(tCharArray, tNewFilePath, strlen(tNewFilePath));
					strncat(tCharArray, "\"", 1);
					*iCount += strlen(tNewFilePath) + 2;
				}else{
					strncat(tCharArray, "\"", 1);
					strncat(tCharArray, "\"", 1);
					*iCount += 2;
				}
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

void formatJSON(ID3_Tag* myTag, char* tCharArray, int* iCount){
	// add the initial curly brace for JSON output
	strncat(tCharArray, "{", 1);
	*iCount += 1;

	// we'll go through each frame printing the ID and printing it's fields
	ID3_Tag::Iterator *iter = myTag->CreateIterator();
	ID3_Frame *myFrame = NULL;
	while(NULL != (myFrame = iter->GetNext())){
		// prints the frame id to the array that you passed in and increments iCount
		printFrameID(myFrame->GetID(), tCharArray, iCount);

		// format the fields as a JSON object
		strncat(tCharArray, ":{", 2);
		*iCount += 2;

		// iterate through the fields and format the field data: fieldID:"data"
		ID3_Frame::Iterator* fieldIter = myFrame->CreateIterator();
		ID3_Field* tField = NULL;
		while(NULL != (tField = fieldIter->GetNext())){
			printme(tField, tCharArray, iCount);

			strncat(tCharArray, ",", 1);
			*iCount += 1;
		}

		// add the trailing JSON curly brace and overwrite the last comma
		tCharArray[*iCount - 1] = '}';

		strncat(tCharArray, ",", 1);
		*iCount += 1;
	}

	// add the trailing JSON curly brace and overwrite the last comma
	tCharArray[*iCount - 1] = '}';
}

int main(int argc, char* argv[])
{
	char* tCharArray = NULL;
	// start at one because we don't care what the program name is
	for(int i = 1; i < argc; i++){
		if(strncmp(argv[i], "-attachments", 11) == 0){
			i++;
			destPath = argv[i];
		}else{
			filePath = argv[i];

			ID3_Tag myTag(filePath);

			tCharArray = new char[myTag.Size()];
			tCharArray[0] = 0;
			int iCount = 0;

			formatJSON(&myTag, tCharArray, &iCount);

			// output to console
			cout << tCharArray << endl;

			// free our memory
			delete[] tCharArray;
		}
	}
	return 0;
}
