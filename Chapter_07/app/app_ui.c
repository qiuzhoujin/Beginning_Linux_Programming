#define _XOPEN_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "cd_data.h"

#define TMP_STRING_LEN 125 /* this number be larger than the biggest
							  single string in any database structure */

typedef enum
{
	mo_invalid,
	mo_add_cat,
	mo_add_tracks,
	mo_del_cat,
	mo_find_cat,
	mo_list_cat_tracks,
	mo_del_tracks,
	mo_count_entries,
	mo_exit
}menu_options;

static int command_mode(int argc, char *argv[]);
static void annouce(void);
static menu_options show_menu(const cdc_entry *current_cdc);
static int get_confirm(const char *question);
static int enter_new_cat_entry(cdc_entry *entry_to_update);
static void enter_new_track_entries(const cdc_entry *entry_to_add_to);
static void del_cat_entry(const cdc_entry *entry_to_delete);
static void del_track_entries(const cdc_entry *entry_to_delete);
static cdc_entry find_cat(void);
static void list_tracks(const cdc_entry *entry_to_use);
static void count_all_entries(void);
static void display_cdc(const cdc_entry *cdc_to_show);
static void display_cdt(const cdt_entry *cdt_to_show);
static void strip_return(char *string_to_strip);

void main(int argc, char *argv[]);
{
	menu_options current_option;
	cdc_entry current_cdc_entry;
	int command_result;

	memset(&current_cdc_entry, '\0', sizeof(current_cdc_entry));

	if (argc > 1)
	{
		command_result = command_mode(argc, argv);
		exit(command_result);
	}

	announce();

	if (!database_initalize(0))
	{
		fprintf(stderr, "Sorry, unable to initialize database\n");
		fprintf(stderr, "To create a new database use %s -i\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while (current_option != mo_exit)
	{
		current_option = show_menu(&current_cdc_entry);

		switch (current_option)
		{
			case mo_add_cat:
				if (enter_new_cat_entry(&current_cdc_entry))
				{
					if (!add_cdc_entry(current_cdc_entry))
					{
						fprintf(stderr, "Failed to add new entry\n");
						memset(&current_cdc_entry, '\0',
								sizeof(current_cdc_entry));
					}
				}
				break;
			case mo_add_tracks:
				enter_new_track_entries(&current_cdc_entry);
				break;
			case mo_del_cat:
				del_cat_entry(&current_cdc_entry);
				break;
			case mo_find_cat:
				current_cdc_entry = find_cat();
				break;
			case mo_list_cat_tracks:
				list_tracks(&current_cdc_entry);
				break;
			case mo_del_tracks:
				del_track_entries(&current_cdc_entry);
				break;
			case mo_count_entries:
				count_all_entries();
				break;
			case mo_exit:
				break;
			case mo_invalid:
				break;
			default:
				break;
		} /* switch */
	} /* while */

	database_close();
	exit(EXIT_SUCCESS);
} /* main */

static void announce(void)
{
	printf("\n\nWelcome to the demonstration CD catalog database \
			program\n");
}

static menu_options show_menu(const cdc_entry *cdc_seletced)
{
	char tmp_str[TMP_STRING_LEN + 1];
	menu_options option_chosen = mo_invalid;

	while (option_chosen == mo_invalid)
	{
		if (cdc_selected->catalog[0])
		{
			printf("\n\nCurrent entry: ");
			printf("%s, %s, %s, %s\n", cdc_seletced->catalog,
					cdc_seletced->title,
					cdc_seletced->type,
					cdc_seletced->artist);

			printf("\n");
			printf("1 - add new CD\n");
			printf("2 - search for a CD\n");
			printf("3 - count the CDs and tracks in the database\n");
			printf("4 - re-enter tracks for current CD\n");
			printf("5 - delete this CD, and all its tracks\n");
			printf("6 - list tracks for this CD\n");
			printf("q - quit\n");
			printf("\nOption: ");
			fgets(tmp_str, TMP_STRING_LEN, stdin);

			switch(tmp_str[0])
			{
				case '1': option_chosen = mo_add_cat; break;
				case '2': option_chosen = mo_find_cat; break;
				case '3': option_chosen = mo_count_entries; break;
				case '4': option_chosen = mo_add_tracks; break;
				case '5': option_chosen = mo_del_cat; break;
				case '6': option_chosen = mo_list_cat_tracks; break;
				case 'q': option_chosen = mo_exit; break;
			}
		}
		else
		{
			printf("\n\n");
			printf("1 - add new CD\n");
			printf("2 - search for a CD\n");
			printf("3 - count the CDs and tracks in the database\n");
			printf("q - quit\n");
			printf("\nOption: ");
			fgets(tmp_str, TMP_STRING_LEN, stdin);
			switch(tmp_str[0])
			{
				case '1': option_chosen = mo_add_cat; break;
				case '2': option_chosen = mo_find_cat; break;
				case '3': option_chosen = mo_count_entries; break;
				case 'q': option_chosen = mo_exit; break;
			}
		}
	} /* while */
	return (option_chosen);
}
