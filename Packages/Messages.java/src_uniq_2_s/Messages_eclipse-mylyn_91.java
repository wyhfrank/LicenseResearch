/*******************************************************************************
 * Copyright (c) 2004, 2010 Tasktop Technologies and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Tasktop Technologies - initial API and implementation
 *******************************************************************************/

package org.eclipse.mylyn.internal.bugzilla.ui.editor;

import org.eclipse.osgi.util.NLS;

public class Messages extends NLS {
	private static final String BUNDLE_NAME = "org.eclipse.mylyn.internal.bugzilla.ui.editor.messages"; //$NON-NLS-1$

	static {
		// load message values from bundle file
		reloadMessages();
	}

	public static void reloadMessages() {
		NLS.initializeMessages(BUNDLE_NAME, Messages.class);
	}

	public static String BugzillaFlagPart_are;

	public static String BugzillaFlagPart_Flags_PartName;

	public static String BugzillaFlagPart_Fleg_Section_Title;

	public static String BugzillaFlagPart_Fleg_Section_Title_Short;

	public static String BugzillaFlagPart_is;

	public static String BugzillaFlagPart_unused_flag;

	public static String BugzillaFlagPart_unused_flags;

	public static String BugzillaFlagPart_used_flag;

	public static String BugzillaFlagPart_used_flags;

	public static String BugzillaPeoplePart_People;

	public static String BugzillaPeoplePart__Select_to_remove_;

	public static String BugzillaPlanningEditorPart_Current_Estimate;

	public static String BugzillaPlanningEditorPart_Team_Planning;

	public static String BugzillaTaskEditorPage_Bug_Line;

	public static String BugzillaTaskEditorPage_Action_Line;

	public static String BugzillaTaskEditorPage_Email_Line;

	public static String BugzillaTaskEditorCommentPart_privateComment;

	public static String BugzillaTaskEditorCommentPart_publicComment;

	public static String BugzillaTaskEditorNewCommentPart_privateComment;

	public static String BugzillaTaskEditorNewCommentPart_publicComment;

	public static String BugzillaTaskEditorPage_Anonymous_can_not_submit_Tasks;

	public static String BugzillaTaskEditorPage_Changes_Submitted_Message;

	public static String BugzillaTaskEditorPage_Confirm;

	public static String BugzillaTaskEditorPage_ConfirmDetailTitle;

	public static String BugzillaTaskEditorPage_Content_Assist_for_Error_Available;

	public static String BugzillaTaskEditorPage_DetailLine;

	public static String BugzillaTaskEditorPage_Error;

	public static String BugzillaTaskEditorPage_Error_Label_1;

	public static String BugzillaTaskEditorPage_Error_Label_N;

	public static String BugzillaTaskEditorPage_ErrorDetailTitle;

	public static String BugzillaTaskEditorPage_Message_more;

	public static String BugzillaTaskEditorPage_Message_one;

	public static String BugzillaTaskEditorPage_Please_enter_a_description_before_submitting;

	public static String BugzillaTaskEditorPage_Please_enter_a_short_summary_before_submitting;

	public static String BugzillaTaskEditorPage_Please_select_a_component_before_submitting;

	public static String BugzillaTaskEditorPage_Please_enter_a_bugid_for_duplicate_of_before_submitting;

	public static String BugzillaTaskEditorPage_submit_disabled_please_refresh;

	public static String BugzillaTaskEditorPage_submitted_Changes_Details;

	public static String BugzillaVotesEditor_Show_votes;

	public static String BugzillaVotesEditor_Vote;
}
