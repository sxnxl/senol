char *strcpy (char *toHere, const char *fromHere) {
	int i=0;
	while(fromHere[i]!='\0'){
		toHere[i]=fromHere[i];
		i++;
	}
	toHere[i]='\0';
	return toHere;
}
