#include "multitask.h"

char*	S_generateSentence()
{
	//you can change these words to generate new sentences
	const char* ARTICLES[] = {"the", "a", "one", "some", "any"};
	const char* NOUNS[] =  {"storage", "cpu", "algorithm", "api", "binary"};
	const char* VERBS[] =  {"generate", "free", "allocate", "reboot", "setup"};
	const int ARTICLES_SIZE = sizeof(ARTICLES)/sizeof(ARTICLES[0]);
	const int NOUNS_SIZE = sizeof(NOUNS)/sizeof(NOUNS[0]);
	const int VERBS_SIZE = sizeof(VERBS)/sizeof(VERBS[0]);

	char* sentence = calloc((25), sizeof(char));

	strcat(sentence, VERBS[rand()%VERBS_SIZE]);
	strcat(sentence, " ");

	strcat(sentence, ARTICLES[rand()%ARTICLES_SIZE]);
	strcat(sentence, " ");

	strcat(sentence, NOUNS[rand()%NOUNS_SIZE]);
	strcat(sentence, " ");

	sentence[0] = toupper(sentence[0]);

	return sentence;
}

void	execute(t_task *head)
{
	int		i = 0;
	char	*str;

	printf("\033[0;31mBegining of execution : %s\033[0m\n**\n", head->Lib_task);
	str = head->Content;
	while (str[i])
	{
		printf("\033[0;33m%c\033[0m", str[i]);
		usleep(17000);//needs modificatiom
		if (!str[i + 1])
		printf("\n**\n");
		i++;
	}
	printf("\033[0;31mEnding of execution : %s\033[0m\n\n\n", head->Lib_task);
}

int	main(void)
{
	char	*sentence;
	int		i = 1;
	t_task  *F_wait = NULL;
	t_task	*new;
	t_task	*tmp;
	t_task	*head_tourniquet = NULL;

	srand(time(NULL));
	while(i <= 30)
	{
		sentence = S_generateSentence();
		new = new_task(sentence, i);
		add_back(&F_wait, new);
		i++;
	}
	i = 0;
	while (i < 30)
	{
		tmp = copy_task(F_wait);
		//should be added to free space
		F_wait = F_wait->next;
		circular_push(&head_tourniquet, tmp);
		execute(head_tourniquet);
		i++;
	}
	return 0;
}