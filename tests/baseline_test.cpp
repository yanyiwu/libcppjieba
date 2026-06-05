#include "include/Application.hpp"
#include "include/Limonp/LocalVector.hpp"

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using CppJieba::Application;
using CppJieba::CutMethod;
using CppJieba::METHOD_FULL;
using CppJieba::METHOD_HMM;
using CppJieba::METHOD_MIX;
using CppJieba::METHOD_MP;
using CppJieba::METHOD_QUERY;
using Limonp::LocalVector;
using Limonp::trim;
using std::cerr;
using std::endl;
using std::pair;
using std::string;
using std::vector;

namespace {

const char* const kSentence =
    "我是拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上CEO，走上人生巅峰。";

bool expectEqual(const vector<string>& actual,
                 const vector<string>& expected,
                 const string& label) {
  if (actual == expected) {
    return true;
  }
  cerr << label << " mismatch" << endl;
  cerr << "expected size: " << expected.size() << ", actual size: "
       << actual.size() << endl;
  return false;
}

bool testCut(Application& app,
             CutMethod method,
             const vector<string>& expected,
             const string& label) {
  vector<string> words;
  app.cut(kSentence, words, method);
  return expectEqual(words, expected, label);
}

bool testSegmentation(Application& app) {
  bool ok = true;

  ok = testCut(app, METHOD_MP,
               {"我", "是", "拖拉机", "学院", "手扶拖拉机", "专业", "的",
                "。", "不用", "多久", "，", "我", "就", "会", "升职",
                "加薪", "，", "当", "上", "C", "E", "O", "，", "走上",
                "人生", "巅峰", "。"},
               "METHOD_MP") &&
       ok;

  ok = testCut(app, METHOD_HMM,
               {"我", "是", "拖拉机", "学院", "手", "扶", "拖拉机", "专业",
                "的", "。", "不用", "多久", "，", "我", "就", "会升",
                "职加薪", "，", "当上", "CEO", "，", "走上", "人生",
                "巅峰", "。"},
               "METHOD_HMM") &&
       ok;

  ok = testCut(app, METHOD_MIX,
               {"我", "是", "拖拉机", "学院", "手扶拖拉机", "专业", "的",
                "。", "不用", "多久", "，", "我", "就", "会", "升职",
                "加薪", "，", "当上", "CEO", "，", "走上", "人生",
                "巅峰", "。"},
               "METHOD_MIX") &&
       ok;

  ok = testCut(app, METHOD_FULL,
               {"我", "是", "拖拉", "拖拉机", "学院", "手扶", "手扶拖拉机",
                "拖拉", "拖拉机", "专业", "的", "。", "不用", "多久",
                "，", "我", "就", "会升", "升职", "加薪", "，", "当上",
                "C", "E", "O", "，", "走上", "人生", "巅峰", "。"},
               "METHOD_FULL") &&
       ok;

  ok = testCut(app, METHOD_QUERY,
               {"我", "是", "拖拉机", "学院", "手扶", "手扶拖拉机", "拖拉",
                "拖拉机", "专业", "的", "。", "不用", "多久", "，", "我",
                "就", "会", "升职", "加薪", "，", "当上", "CEO", "，",
                "走上", "人生", "巅峰", "。"},
               "METHOD_QUERY") &&
       ok;

  return ok;
}

bool testTagging(Application& app) {
  vector<pair<string, string> > tags;
  app.tag(kSentence, tags);

  const vector<pair<string, string> > expected = {
      {"我", "r"},      {"是", "v"},      {"拖拉机", "n"},
      {"学院", "n"},    {"手扶拖拉机", "n"}, {"专业", "n"},
      {"的", "uj"},     {"。", "x"},      {"不用", "v"},
      {"多久", "m"},    {"，", "x"},      {"我", "r"},
      {"就", "d"},      {"会", "v"},      {"升职", "v"},
      {"加薪", "nr"},   {"，", "x"},      {"当上", "t"},
      {"CEO", "eng"},   {"，", "x"},      {"走上", "v"},
      {"人生", "n"},    {"巅峰", "n"},    {"。", "x"}};

  if (tags == expected) {
    return true;
  }
  cerr << "tagging mismatch" << endl;
  return false;
}

bool testKeywordExtraction(Application& app) {
  vector<pair<string, double> > keywords;
  app.extract(kSentence, keywords, 5);

  const vector<string> expected_words = {
      "CEO", "升职", "加薪", "手扶拖拉机", "巅峰"};

  if (keywords.size() != expected_words.size()) {
    cerr << "keyword size mismatch" << endl;
    return false;
  }

  for (size_t i = 0; i < expected_words.size(); ++i) {
    if (keywords[i].first != expected_words[i]) {
      cerr << "keyword mismatch at " << i << endl;
      return false;
    }
  }
  return true;
}

bool testLocalVectorPointerRange() {
  const int values[] = {1, 2, 3};
  LocalVector<int> vec(values, values + 3);

  if (vec.size() != 3 || vec[0] != 1 || vec[1] != 2 || vec[2] != 3) {
    cerr << "LocalVector pointer range construction mismatch" << endl;
    return false;
  }
  return true;
}

bool testStringTrim() {
  string spaces = " \ttrim me\n";
  string hashes = "###trim me###";

  if (trim(spaces) != "trim me") {
    cerr << "whitespace trim mismatch" << endl;
    return false;
  }

  if (trim(hashes, '#') != "trim me") {
    cerr << "character trim mismatch" << endl;
    return false;
  }

  return true;
}

}  // namespace

int main() {
  Application app("./dict/jieba.dict.utf8",
                  "./dict/hmm_model.utf8",
                  "./dict/user.dict.utf8",
                  "./dict/idf.utf8",
                  "./dict/stop_words.utf8");

  bool ok = true;
  ok = testSegmentation(app) && ok;
  ok = testTagging(app) && ok;
  ok = testKeywordExtraction(app) && ok;
  ok = testLocalVectorPointerRange() && ok;
  ok = testStringTrim() && ok;

  if (!ok) {
    return EXIT_FAILURE;
  }

  std::cout << "baseline tests passed" << std::endl;
  return EXIT_SUCCESS;
}
