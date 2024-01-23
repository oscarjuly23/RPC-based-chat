/* basedChat.x: Remote based chat protocol */

 program PROGRAMA_CHAT {
     version VERSION_CHAT {
        int write (string) = 1;
        string getChat (void) = 2;
 	 } = 1;
} = 0x20000001;
