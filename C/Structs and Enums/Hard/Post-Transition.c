#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;

int stringEqual (const char* a, const char* b) {
    int i = 0;
    int j = 0;
    while (1) {
        char c1 = *(a+i);
        char c2 = *(b+j);
        if (c1 == '\0') {
            if (c2 == '\0')
                return 1;
            return 0;
        } else if (c2 == '\0')
            return 0;
        
        if (c1 != c2)
            return 0;
        ++i;
        ++j;
    }
    return 1;
}

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    int post_office_counter = 0;
    for (int i = 0; i < t.offices_count; ++i) {
        printf("\t%d:\n", post_office_counter);
        for (int j = 0; j < (*(t.offices + i)).packages_count; ++j) {
            printf("\t\t%s\n", (*(((*(t.offices + i)).packages) + j)).id);
        }
        post_office_counter++;
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    int target_min_weight = ((target->offices)+target_office_index)->min_weight;
    int target_max_weight = ((target->offices)+target_office_index)->max_weight;
    int target_old_packages_count = ((target->offices) + target_office_index)
                                        ->packages_count;
    int source_old_packages_count =
        ((source->offices) + source_office_index)->packages_count;
    package* target_new_packages = malloc((target_old_packages_count + source_old_packages_count) * sizeof(package));
    for (int i = 0; i < target_old_packages_count; ++i) {
        package* p = (((target->offices) + target_office_index)->packages)+i;
        *(target_new_packages+i) = *p;
    }

    package* source_new_packages = malloc(source_old_packages_count*sizeof(package));

    int target_new_packages_count = target_old_packages_count;
    int source_new_packages_count = 0;
    for (int i = 0; i < source_old_packages_count; ++i) {
        package *p = (((source->offices) + source_office_index)->packages) + i;
        if (p->weight >= target_min_weight && p->weight <= target_max_weight) {
            *(target_new_packages + target_new_packages_count) = *p;
            target_new_packages_count++;
        } else {
            *(source_new_packages+source_new_packages_count) = *p;
            source_new_packages_count++;
        }
    }

    source_new_packages = realloc(source_new_packages,
                                  source_new_packages_count * sizeof(package));
    target_new_packages = realloc(target_new_packages,
                                  target_new_packages_count * sizeof(package));

    post_office* source_office = (source->offices) + source_office_index;
    source_office->packages = source_new_packages;
    source_office->packages_count = source_new_packages_count;

    post_office* target_office = (target->offices) + target_office_index;
    target_office->packages = target_new_packages;
    target_office->packages_count = target_new_packages_count;
}

town town_with_most_packages(town* towns, int towns_count) {
    int most_packages = 0;
    town* most_packages_town = NULL;

    for (int i = 0; i < towns_count; ++i) {
        int packages = 0;
        for (int j = 0; j < (towns+i)->offices_count; ++j) {
            packages += (((towns+i)->offices)+j)->packages_count;
        }
        if (packages > most_packages) {
            most_packages = packages;
            most_packages_town = towns+i;
        }
    }

    return *most_packages_town;
}

town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; ++i) {
        if (stringEqual((towns+i)->name, name) == 1)
            return towns+i;
    }
    return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}

