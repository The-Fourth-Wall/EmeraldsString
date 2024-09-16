#ifndef __EMERALDS_STRING_SUBSTRING_MODULE_SPEC_H_
#define __EMERALDS_STRING_SUBSTRING_MODULE_SPEC_H_

#include "../libs/cSpec/export/cSpec.h"
#include "../src/EmeraldsString.h"

module(T_string_substring, {
  describe("string substring", {
    it("returns a null string when given a null string", {
      char *str = NULL;
      char *sub = string_substring(str, 0, 0);
      assert_that(str is NULL);
      assert_that(sub is NULL);
    });

    it("returns an empty string when given an empty string", {
      char *str = string_new("");
      char *sub = string_substring(str, 0, 0);
      assert_that(str isnot NULL);
      assert_that(sub isnot NULL);
      assert_that_charptr(str equals to "");
      assert_that_charptr(sub equals to "");
      char *sub1 = string_substring(str, 0, 1);
      assert_that_charptr(sub1 equals to "");
      char *sub2 = string_substring(str, 3, 6);
      assert_that_charptr(sub2 equals to "");
      char *sub3 = string_substring(str, 6, 3);
      assert_that_charptr(sub3 equals to "");
    });

    it("returns an empty string when getting sub of similar position", {
      char *str  = string_new("oblivious");
      char *sub0 = string_substring(str, 0, 0);
      assert_that_charptr(sub0 equals to "");
      char *sub1 = string_substring(str, 1, 1);
      assert_that_charptr(sub1 equals to "");
      char *sub2 = string_substring(str, 2, 2);
      assert_that_charptr(sub2 equals to "");
      char *sub3 = string_substring(str, 3, 3);
      assert_that_charptr(sub3 equals to "");
      char *sub9 = string_substring(str, 9, 9);
      assert_that_charptr(sub9 equals to "");
      char *subx = string_substring(str, 42, 42);
      assert_that_charptr(subx equals to "");
    });

    it("grabs the first character of a string", {
      char *str  = string_new("oblivious");
      char *sub1 = string_substring(str, 0, 1);
      assert_that_charptr(sub1 equals to "o");
      char *sub2 = string_substring(str, 3, 4);
      assert_that_charptr(sub2 equals to "i");
    });

    it("grabs multiple characters in a string", {
      char *str  = string_new("oblivious");
      char *sub1 = string_substring(str, 0, 2);
      assert_that_charptr(sub1 equals to "ob");
      char *sub2 = string_substring(str, 3, 6);
      assert_that_charptr(sub2 equals to "ivi");
    });

    it("returns an emprty string when `from` is greater than `to`", {
      char *str  = string_new("oblivious");
      char *sub1 = string_substring(str, 3, 2);
      assert_that_charptr(sub1 equals to "");
      char *sub2 = string_substring(str, 5, 3);
      assert_that_charptr(sub2 equals to "");
    });

    context("handles negative numbers", {
      it("shortens the string by the when given a negative `to`", {
        char *str  = string_new("oblivious");
        char *sub1 = string_substring(str, 0, -1);
        assert_that_charptr(sub1 equals to "obliviou");
        char *sub2 = string_substring(str, 0, -2);
        assert_that_charptr(sub2 equals to "oblivio");
        char *sub3 = string_substring(str, 0, -3);
        assert_that_charptr(sub3 equals to "oblivi");
        char *sub4 = string_substring(str, 0, -4);
        assert_that_charptr(sub4 equals to "obliv");
        char *sub5 = string_substring(str, 0, -9);
        assert_that_charptr(sub5 equals to "");
        char *sub6 = string_substring(str, 0, -42);
        assert_that_charptr(sub6 equals to "");
        char *sub7 = string_substring(str, 2, -2);
        assert_that_charptr(sub7 equals to "livio");
        char *sub8 = string_substring(str, 3, -5);
        assert_that_charptr(sub8 equals to "i");
        char *sub9 = string_substring(str, 4, -5);
        assert_that_charptr(sub9 equals to "");
      });

      it(
        "skips the first characters by the number of chracters when given a "
        "negative `from`",
        {
          char *str  = string_new("oblivious");
          char *sub1 = string_substring(str, -1, 0);
          assert_that_charptr(sub1 equals to "");
          char *sub2 = string_substring(str, -2, 0);
          assert_that_charptr(sub2 equals to "");
          char *sub3 = string_substring(str, -3, 0);
          assert_that_charptr(sub3 equals to "");
          char *sub4 = string_substring(str, -42, 0);
          assert_that_charptr(sub4 equals to "");
          char *sub5 = string_substring(str, -1, -1);
          assert_that_charptr(sub5 equals to "");
          char *sub6 = string_substring(str, -5, -2);
          assert_that_charptr(sub6 equals to "vio");
          char *sub7 = string_substring(str, -7, 9);
          assert_that_charptr(sub7 equals to "livious");
        }
      );
    });

    it("tests comprehensive cases of potential substrings", {
      char *str = string_new("oblivious");
      assert_that_charptr(string_substring(str, 0, 1) equals to "o");
      assert_that_charptr(string_substring(str, 0, 2) equals to "ob");
      assert_that_charptr(string_substring(str, 0, 3) equals to "obl");
      assert_that_charptr(string_substring(str, 0, 4) equals to "obli");
      assert_that_charptr(string_substring(str, 0, 5) equals to "obliv");
      assert_that_charptr(string_substring(str, 0, 6) equals to "oblivi");
      assert_that_charptr(string_substring(str, 0, 7) equals to "oblivio");
      assert_that_charptr(string_substring(str, 0, 8) equals to "obliviou");
      assert_that_charptr(string_substring(str, 0, 9) equals to "oblivious");
      assert_that_charptr(string_substring(str, 1, 2) equals to "b");
      assert_that_charptr(string_substring(str, 1, 3) equals to "bl");
      assert_that_charptr(string_substring(str, 1, 4) equals to "bli");
      assert_that_charptr(string_substring(str, 1, 5) equals to "bliv");
      assert_that_charptr(string_substring(str, 1, 6) equals to "blivi");
      assert_that_charptr(string_substring(str, 1, 7) equals to "blivio");
      assert_that_charptr(string_substring(str, 1, 8) equals to "bliviou");
      assert_that_charptr(string_substring(str, 1, 9) equals to "blivious");
      assert_that_charptr(string_substring(str, 2, 3) equals to "l");
      assert_that_charptr(string_substring(str, 2, 4) equals to "li");
      assert_that_charptr(string_substring(str, 2, 5) equals to "liv");
      assert_that_charptr(string_substring(str, 2, 6) equals to "livi");
      assert_that_charptr(string_substring(str, 2, 7) equals to "livio");
      assert_that_charptr(string_substring(str, 2, 8) equals to "liviou");
      assert_that_charptr(string_substring(str, 2, 9) equals to "livious");
      assert_that_charptr(string_substring(str, 3, 4) equals to "i");
      assert_that_charptr(string_substring(str, 3, 5) equals to "iv");
      assert_that_charptr(string_substring(str, 3, 6) equals to "ivi");
      assert_that_charptr(string_substring(str, 3, 7) equals to "ivio");
      assert_that_charptr(string_substring(str, 3, 8) equals to "iviou");
      assert_that_charptr(string_substring(str, 3, 9) equals to "ivious");
      assert_that_charptr(string_substring(str, 4, 5) equals to "v");
      assert_that_charptr(string_substring(str, 4, 6) equals to "vi");
      assert_that_charptr(string_substring(str, 4, 7) equals to "vio");
      assert_that_charptr(string_substring(str, 4, 8) equals to "viou");
      assert_that_charptr(string_substring(str, 4, 9) equals to "vious");
      assert_that_charptr(string_substring(str, 5, 6) equals to "i");
      assert_that_charptr(string_substring(str, 5, 7) equals to "io");
      assert_that_charptr(string_substring(str, 5, 8) equals to "iou");
      assert_that_charptr(string_substring(str, 5, 9) equals to "ious");
      assert_that_charptr(string_substring(str, 6, 7) equals to "o");
      assert_that_charptr(string_substring(str, 6, 8) equals to "ou");
      assert_that_charptr(string_substring(str, 6, 9) equals to "ous");
      assert_that_charptr(string_substring(str, 7, 8) equals to "u");
      assert_that_charptr(string_substring(str, 7, 9) equals to "us");
      assert_that_charptr(string_substring(str, 8, 9) equals to "s");
      assert_that_charptr(string_substring(str, 0, 3) equals to "obl");
      assert_that_charptr(string_substring(str, 1, 4) equals to "bli");
      assert_that_charptr(string_substring(str, 2, 5) equals to "liv");
      assert_that_charptr(string_substring(str, 3, 6) equals to "ivi");
      assert_that_charptr(string_substring(str, 4, 7) equals to "vio");
      assert_that_charptr(string_substring(str, 5, 8) equals to "iou");
      assert_that_charptr(string_substring(str, 6, 9) equals to "ous");
      assert_that_charptr(string_substring(str, -9, -8) equals to "o");
      assert_that_charptr(string_substring(str, -9, -7) equals to "ob");
      assert_that_charptr(string_substring(str, -9, -6) equals to "obl");
      assert_that_charptr(string_substring(str, -9, -5) equals to "obli");
      assert_that_charptr(string_substring(str, -9, -4) equals to "obliv");
      assert_that_charptr(string_substring(str, -9, -3) equals to "oblivi");
      assert_that_charptr(string_substring(str, -9, -2) equals to "oblivio");
      assert_that_charptr(string_substring(str, -9, -1) equals to "obliviou");
      assert_that_charptr(string_substring(str, -9, 0) equals to "");
      assert_that_charptr(string_substring(str, -9, 1) equals to "o");
      assert_that_charptr(string_substring(str, -9, 2) equals to "ob");
      assert_that_charptr(string_substring(str, -9, 3) equals to "obl");
      assert_that_charptr(string_substring(str, -9, 4) equals to "obli");
      assert_that_charptr(string_substring(str, -9, 5) equals to "obliv");
      assert_that_charptr(string_substring(str, -9, 6) equals to "oblivi");
      assert_that_charptr(string_substring(str, -9, 7) equals to "oblivio");
      assert_that_charptr(string_substring(str, -9, 8) equals to "obliviou");
      assert_that_charptr(string_substring(str, -9, 9) equals to "oblivious");
      assert_that_charptr(string_substring(str, -8, -7) equals to "b");
      assert_that_charptr(string_substring(str, -8, -6) equals to "bl");
      assert_that_charptr(string_substring(str, -8, -5) equals to "bli");
      assert_that_charptr(string_substring(str, -8, -4) equals to "bliv");
      assert_that_charptr(string_substring(str, -8, -3) equals to "blivi");
      assert_that_charptr(string_substring(str, -8, -2) equals to "blivio");
      assert_that_charptr(string_substring(str, -8, -1) equals to "bliviou");
      assert_that_charptr(string_substring(str, -8, 0) equals to "");
      assert_that_charptr(string_substring(str, -8, 1) equals to "");
      assert_that_charptr(string_substring(str, -8, 2) equals to "b");
      assert_that_charptr(string_substring(str, -8, 3) equals to "bl");
      assert_that_charptr(string_substring(str, -8, 4) equals to "bli");
      assert_that_charptr(string_substring(str, -8, 5) equals to "bliv");
      assert_that_charptr(string_substring(str, -8, 6) equals to "blivi");
      assert_that_charptr(string_substring(str, -8, 7) equals to "blivio");
      assert_that_charptr(string_substring(str, -8, 8) equals to "bliviou");
      assert_that_charptr(string_substring(str, -8, 9) equals to "blivious");
      assert_that_charptr(string_substring(str, -7, -6) equals to "l");
      assert_that_charptr(string_substring(str, -7, -5) equals to "li");
      assert_that_charptr(string_substring(str, -7, -4) equals to "liv");
      assert_that_charptr(string_substring(str, -7, -3) equals to "livi");
      assert_that_charptr(string_substring(str, -7, -2) equals to "livio");
      assert_that_charptr(string_substring(str, -7, -1) equals to "liviou");
      assert_that_charptr(string_substring(str, -7, 0) equals to "");
      assert_that_charptr(string_substring(str, -7, 1) equals to "");
      assert_that_charptr(string_substring(str, -7, 2) equals to "");
      assert_that_charptr(string_substring(str, -7, 3) equals to "l");
      assert_that_charptr(string_substring(str, -7, 4) equals to "li");
      assert_that_charptr(string_substring(str, -7, 5) equals to "liv");
      assert_that_charptr(string_substring(str, -7, 6) equals to "livi");
      assert_that_charptr(string_substring(str, -7, 7) equals to "livio");
      assert_that_charptr(string_substring(str, -7, 8) equals to "liviou");
      assert_that_charptr(string_substring(str, -7, 9) equals to "livious");
      assert_that_charptr(string_substring(str, -6, -5) equals to "i");
      assert_that_charptr(string_substring(str, -6, -4) equals to "iv");
      assert_that_charptr(string_substring(str, -6, -3) equals to "ivi");
      assert_that_charptr(string_substring(str, -6, -2) equals to "ivio");
      assert_that_charptr(string_substring(str, -6, -1) equals to "iviou");
      assert_that_charptr(string_substring(str, -6, 0) equals to "");
      assert_that_charptr(string_substring(str, -6, 1) equals to "");
      assert_that_charptr(string_substring(str, -6, 2) equals to "");
      assert_that_charptr(string_substring(str, -6, 3) equals to "");
      assert_that_charptr(string_substring(str, -6, 4) equals to "i");
      assert_that_charptr(string_substring(str, -6, 5) equals to "iv");
      assert_that_charptr(string_substring(str, -6, 6) equals to "ivi");
      assert_that_charptr(string_substring(str, -6, 7) equals to "ivio");
      assert_that_charptr(string_substring(str, -6, 8) equals to "iviou");
      assert_that_charptr(string_substring(str, -6, 9) equals to "ivious");
      assert_that_charptr(string_substring(str, -5, -4) equals to "v");
      assert_that_charptr(string_substring(str, -5, -3) equals to "vi");
      assert_that_charptr(string_substring(str, -5, -2) equals to "vio");
      assert_that_charptr(string_substring(str, -5, -1) equals to "viou");
      assert_that_charptr(string_substring(str, -5, 0) equals to "");
      assert_that_charptr(string_substring(str, -5, 1) equals to "");
      assert_that_charptr(string_substring(str, -5, 2) equals to "");
      assert_that_charptr(string_substring(str, -5, 3) equals to "");
      assert_that_charptr(string_substring(str, -5, 4) equals to "");
      assert_that_charptr(string_substring(str, -5, 5) equals to "v");
      assert_that_charptr(string_substring(str, -5, 6) equals to "vi");
      assert_that_charptr(string_substring(str, -5, 7) equals to "vio");
      assert_that_charptr(string_substring(str, -5, 8) equals to "viou");
      assert_that_charptr(string_substring(str, -5, 9) equals to "vious");
      assert_that_charptr(string_substring(str, -4, -3) equals to "i");
      assert_that_charptr(string_substring(str, -4, -2) equals to "io");
      assert_that_charptr(string_substring(str, -4, -1) equals to "iou");
      assert_that_charptr(string_substring(str, -4, 0) equals to "");
      assert_that_charptr(string_substring(str, -4, 1) equals to "");
      assert_that_charptr(string_substring(str, -4, 2) equals to "");
      assert_that_charptr(string_substring(str, -4, 3) equals to "");
      assert_that_charptr(string_substring(str, -4, 4) equals to "");
      assert_that_charptr(string_substring(str, -4, 5) equals to "");
      assert_that_charptr(string_substring(str, -4, 6) equals to "i");
      assert_that_charptr(string_substring(str, -4, 7) equals to "io");
      assert_that_charptr(string_substring(str, -4, 8) equals to "iou");
      assert_that_charptr(string_substring(str, -4, 9) equals to "ious");
      assert_that_charptr(string_substring(str, -3, -2) equals to "o");
      assert_that_charptr(string_substring(str, -3, -1) equals to "ou");
      assert_that_charptr(string_substring(str, -3, 0) equals to "");
      assert_that_charptr(string_substring(str, -3, 1) equals to "");
      assert_that_charptr(string_substring(str, -3, 2) equals to "");
      assert_that_charptr(string_substring(str, -3, 3) equals to "");
      assert_that_charptr(string_substring(str, -3, 4) equals to "");
      assert_that_charptr(string_substring(str, -3, 5) equals to "");
      assert_that_charptr(string_substring(str, -3, 6) equals to "");
      assert_that_charptr(string_substring(str, -3, 7) equals to "o");
      assert_that_charptr(string_substring(str, -3, 8) equals to "ou");
      assert_that_charptr(string_substring(str, -3, 9) equals to "ous");
      assert_that_charptr(string_substring(str, -2, -1) equals to "u");
      assert_that_charptr(string_substring(str, -2, 0) equals to "");
      assert_that_charptr(string_substring(str, -2, 1) equals to "");
      assert_that_charptr(string_substring(str, -2, 2) equals to "");
      assert_that_charptr(string_substring(str, -2, 3) equals to "");
      assert_that_charptr(string_substring(str, -2, 4) equals to "");
      assert_that_charptr(string_substring(str, -2, 5) equals to "");
      assert_that_charptr(string_substring(str, -2, 6) equals to "");
      assert_that_charptr(string_substring(str, -2, 7) equals to "");
      assert_that_charptr(string_substring(str, -2, 8) equals to "u");
      assert_that_charptr(string_substring(str, -2, 9) equals to "us");
      assert_that_charptr(string_substring(str, -1, 0) equals to "");
      assert_that_charptr(string_substring(str, -1, 1) equals to "");
      assert_that_charptr(string_substring(str, -1, 2) equals to "");
      assert_that_charptr(string_substring(str, -1, 3) equals to "");
      assert_that_charptr(string_substring(str, -1, 4) equals to "");
      assert_that_charptr(string_substring(str, -1, 5) equals to "");
      assert_that_charptr(string_substring(str, -1, 6) equals to "");
      assert_that_charptr(string_substring(str, -1, 7) equals to "");
      assert_that_charptr(string_substring(str, -1, 8) equals to "");
      assert_that_charptr(string_substring(str, -1, 9) equals to "s");
      assert_that_charptr(string_substring(str, 0, -8) equals to "o");
      assert_that_charptr(string_substring(str, 0, -7) equals to "ob");
      assert_that_charptr(string_substring(str, 0, -6) equals to "obl");
      assert_that_charptr(string_substring(str, 0, -5) equals to "obli");
      assert_that_charptr(string_substring(str, 0, -4) equals to "obliv");
      assert_that_charptr(string_substring(str, 0, -3) equals to "oblivi");
      assert_that_charptr(string_substring(str, 0, -2) equals to "oblivio");
      assert_that_charptr(string_substring(str, 0, -1) equals to "obliviou");
      assert_that_charptr(string_substring(str, 0, 0) equals to "");
      assert_that_charptr(string_substring(str, 0, 1) equals to "o");
      assert_that_charptr(string_substring(str, 0, 2) equals to "ob");
      assert_that_charptr(string_substring(str, 0, 3) equals to "obl");
      assert_that_charptr(string_substring(str, 0, 4) equals to "obli");
      assert_that_charptr(string_substring(str, 0, 5) equals to "obliv");
      assert_that_charptr(string_substring(str, 0, 6) equals to "oblivi");
      assert_that_charptr(string_substring(str, 0, 7) equals to "oblivio");
      assert_that_charptr(string_substring(str, 0, 8) equals to "obliviou");
      assert_that_charptr(string_substring(str, 0, 9) equals to "oblivious");
      assert_that_charptr(string_substring(str, 1, -7) equals to "b");
      assert_that_charptr(string_substring(str, 1, -6) equals to "bl");
      assert_that_charptr(string_substring(str, 1, -5) equals to "bli");
      assert_that_charptr(string_substring(str, 1, -4) equals to "bliv");
      assert_that_charptr(string_substring(str, 1, -3) equals to "blivi");
      assert_that_charptr(string_substring(str, 1, -2) equals to "blivio");
      assert_that_charptr(string_substring(str, 1, -1) equals to "bliviou");
    });
  });
})

#endif
