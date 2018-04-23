#ifndef ESCHER_EXPRESSION_FIELD_H
#define ESCHER_EXPRESSION_FIELD_H

#include <escher/expression_layout_field.h>
#include <escher/expression_layout_field_delegate.h>
#include <escher/text_field.h>
#include <escher/text_field_delegate.h>
#include <poincare/expression_layout.h>

class ExpressionField : public Responder, public View {
public:
  ExpressionField(Responder * parentResponder, char * textBuffer, int textBufferLength, Poincare::ExpressionLayout * layout, TextFieldDelegate * textFieldDelegate, ExpressionLayoutFieldDelegate * expressionLayoutFieldDelegate);

  void setEditing(bool isEditing, bool reinitDraftBuffer = true);
  bool isEditing() const;
  const char * text();
  void setText(const char * text);
  void insertText(const char * text);
  void reload();
  bool editionIsInTextField() const;
  bool isEmpty() const;
  bool heightIsMaximal() const;
  bool handleEventWithText(const char * text, bool indentation = false) override;

  /* View */
  int numberOfSubviews() const override { return 1; }
  View * subviewAtIndex(int index) override;
  void layoutSubviews() override;
  void drawRect(KDContext * ctx, KDRect rect) const override;
  KDSize minimalSizeForOptimalDisplay() const override;

  /* Responder */
  bool handleEvent(Ion::Events::Event event) override;

private:
  static constexpr KDCoordinate k_textFieldHeight = 37;
  static constexpr KDCoordinate k_leftMargin = 5;
  static constexpr KDCoordinate k_verticalExpressionViewMargin = 5;
  constexpr static int k_separatorThickness = 1;
  KDCoordinate inputViewHeight() const;
  KDCoordinate maximalHeight() const;
  TextField m_textField;
  ExpressionLayoutField m_expressionLayoutField;
  char *  m_textBuffer;
  int m_textBufferLength;
};

#endif
