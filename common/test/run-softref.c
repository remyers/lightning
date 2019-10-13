#include <assert.h>
#include <ccan/short_types/short_types.h>
#include <stdio.h>
#include <wire/wire.h>

/* AUTOGENERATED MOCKS START */
/* Generated stub for amount_asset_is_main */
bool amount_asset_is_main(struct amount_asset *asset UNNEEDED)
{ fprintf(stderr, "amount_asset_is_main called!\n"); abort(); }
/* Generated stub for amount_asset_to_sat */
struct amount_sat amount_asset_to_sat(struct amount_asset *asset UNNEEDED)
{ fprintf(stderr, "amount_asset_to_sat called!\n"); abort(); }
/* Generated stub for amount_sat_add */
 bool amount_sat_add(struct amount_sat *val UNNEEDED,
				       struct amount_sat a UNNEEDED,
				       struct amount_sat b UNNEEDED)
{ fprintf(stderr, "amount_sat_add called!\n"); abort(); }
/* Generated stub for amount_sat_eq */
bool amount_sat_eq(struct amount_sat a UNNEEDED, struct amount_sat b UNNEEDED)
{ fprintf(stderr, "amount_sat_eq called!\n"); abort(); }
/* Generated stub for amount_sat_sub */
 bool amount_sat_sub(struct amount_sat *val UNNEEDED,
				       struct amount_sat a UNNEEDED,
				       struct amount_sat b UNNEEDED)
{ fprintf(stderr, "amount_sat_sub called!\n"); abort(); }
/* Generated stub for fromwire_fail */
const void *fromwire_fail(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_fail called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

struct objtype {
	char *c_softref, *c_softref2;
};

int main(void)
{
	const void *ctx = tal(NULL, char);
	struct objtype *o;
	char *c;

	setup_locale();

	/* Simple test: freeing obj NULLs softref */
	o = tal(ctx, struct objtype);
	c = tal(ctx, char);
	set_softref(o, &o->c_softref, c);
	assert(o->c_softref == c);

	tal_free(c);
	assert(o->c_softref == NULL);\

	/* Duplicate ptrs work */
	o = tal(ctx, struct objtype);
	c = tal(ctx, char);
	set_softref(o, &o->c_softref, c);
	assert(o->c_softref == c);
	set_softref(o, &o->c_softref2, c);
	assert(o->c_softref2 == c);

	tal_free(c);
	assert(o->c_softref == NULL);
	assert(o->c_softref2 == NULL);

	/* Cleans up properly if o is freed first. */
	c = tal(ctx, char);
	set_softref(o, &o->c_softref, c);
	tal_free(o);
	tal_free(c);

	/* Setting to NULL works. */
	o = tal(ctx, struct objtype);
	c = tal(ctx, char);
	set_softref(o, &o->c_softref, c);
	assert(o->c_softref == c);
	clear_softref(o, &o->c_softref);
	assert(o->c_softref == NULL);

	/* Now it's not a softref, won't clear! */
	o->c_softref = c;
	tal_free(c);
	assert(o->c_softref == c);
	tal_free(o);

	tal_free(ctx);
}