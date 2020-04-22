#include "graphic.h"
#include "free.h"

void destroy_unused_rects(void)
{
	/* implemente isso! */
	/* XXX */

	struct rect_list_type *current = rect_list;
	struct rect_list_type *old = NULL;
	while (current != NULL) {
		if (current->rect.x + current->rect.w > WINDOW_WIDTH) {
			struct rect_list_type *dying = current;
			if (old != NULL) {
				old->next = current->next;
			}
			current = current->next;
			free(dying);
			continue;
		}
		old = current;
		current = current->next;
	}

	/* XXX */
}
