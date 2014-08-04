/*******************************************************************************
 * Copyright (c) 2004, 2009 Tasktop Technologies and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Tasktop Technologies - initial API and implementation
 *******************************************************************************/

package org.eclipse.mylyn.internal.provisional.tasks.ui.wizards;

import org.eclipse.osgi.util.NLS;

public class Messages extends NLS {
	private static final String BUNDLE_NAME = "org.eclipse.mylyn.internal.provisional.tasks.ui.wizards.messages"; //$NON-NLS-1$

	static {
		// load message values from bundle file
		reloadMessages();
	}

	public static void reloadMessages() {
		NLS.initializeMessages(BUNDLE_NAME, Messages.class);
	}

	public static String AbstractRepositoryQueryPage2__Refresh_From_Repository;

	public static String AbstractRepositoryQueryPage2__Title_;

	public static String AbstractRepositoryQueryPage2_Create_a_Query_Page_Description;

	public static String AbstractRepositoryQueryPage2_Enter_a_title;

	public static String AbstractRepositoryQueryPage2_Enter_query_parameters;

	public static String AbstractRepositoryQueryPage2_No_repository_available_please_add_one_using_the_Task_Repositories_view;

	public static String AbstractRepositoryQueryPage2_Update_Attributes_Failed;
}
